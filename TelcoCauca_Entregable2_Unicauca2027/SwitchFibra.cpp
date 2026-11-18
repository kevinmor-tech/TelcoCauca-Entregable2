#include "SwitchFibra.h"
#include "RegistroSeguro.h"
#include <chrono>
#include <stdexcept>
#include <thread>

SwitchFibra::SwitchFibra(const std::string& id, int puertos)
    : DispositivoComunicacion(id, "Switch de fibra"),
      puertosActivos(puertos) {
    if (puertos < 0)
        throw std::invalid_argument("Puertos activos negativos.");
}

void SwitchFibra::transmitir() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    registrarEventoSeguro("Switch " + id +
        ": enlace de fibra; puertos activos: " +
        std::to_string(puertosActivos));
}
