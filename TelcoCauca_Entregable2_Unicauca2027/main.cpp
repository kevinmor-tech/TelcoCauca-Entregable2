#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "RegistroSeguro.h"
#include "EventoIngenieria2027.h"

#include <exception>
#include <functional> // std::ref, std::cref
#include <stdexcept>
#include <thread>
#include <vector>

// std::ref pasa una referencia al puntero guardado en el vector.
// La estructura 'red' permanece sin modificaciones mientras hay hilos activos.
void tareaTransmisionHilo(DispositivoComunicacion*& dev) {
    try {
        if (dev == nullptr)
            throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");

        dev->transmitir(); // polimorfismo dinamico
        registrarTransmisionExitosa();
        registrarEventoSeguro("Transmision correcta: " + dev->getId());
    } catch (const std::exception& e) {
        registrarTransmisionFallida();
        registrarEventoSeguro(std::string("EXCEPCION EN HILO: ") + e.what());
    } catch (...) {
        registrarTransmisionFallida();
        registrarEventoSeguro("EXCEPCION EN HILO: error desconocido.");
    }
}

int main() {
    // Dispositivos de TelcoCauca: el nullptr prueba la guarda defensiva.
    std::vector<DispositivoComunicacion*> red;
    red.push_back(new RouterWiFi("RTR-01", 12));
    red.push_back(new GatewayLoRa("GW-868", 868.1f));
    red.push_back(new SwitchFibra("SW-01", 8));
    red.push_back(nullptr);

    // Dos actividades institucionales documentadas y una propuesta FIET.
    // No se asignan fechas que aun no esten oficialmente publicadas.
    const std::vector<EventoIngenieria2027> agenda = {
        {"Bicentenario de la Universidad del Cauca (1827-2027)",
         "Historia y comunidad universitaria", "2027",
         "Confirmado: aniversario institucional",
         "unicauca.edu.co/noticias-actualidad/unicauca-se-viste-desde-ya-de-bicentenario/"},
        {"Agenda academica y cultural del Bicentenario",
         "Academia, cultura y patrimonio", "2027 - fechas por anunciar",
         "En preparacion: Comision Bicentenario",
         "unicauca.edu.co/la-universidad/rectoria/cegeco/comision-bicentenario/"},
        {"Encuentro FIET: tecnologia y telecomunicaciones hacia 2027",
         "Ingenieria Electronica y Telecomunicaciones", "2027 - sin fecha",
         "Propuesta academica del proyecto; NO es evento oficial",
         "unicauca.edu.co/vicerrectoria-academica/facultad-de-ingenieria-electronica-y-telecomunicaciones/"}
    };

    std::vector<std::thread> hilos;
    for (std::size_t i = 0; i < red.size(); ++i)
        hilos.emplace_back(tareaTransmisionHilo, std::ref(red[i]));

    // Un hilo propio para la agenda. std::cref evita copiar el vector.
    hilos.emplace_back(mostrarAgenda2027, std::cref(agenda));

    // main espera: NO eliminar objetos hasta que sus hilos terminen.
    for (auto& hilo : hilos) {
        if (hilo.joinable())
            hilo.join();
    }

    mostrarResumenSeguro();

    for (auto& dev : red) {
        delete dev; // destructor virtual; delete nullptr es seguro
        dev = nullptr;
    }
    red.clear(); // clear NO sustituye a delete.
    registrarEventoSeguro("Sistema TelcoCauca finalizado correctamente.");
    return 0;
}
