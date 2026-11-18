#include "RouterWiFi.h"
#include "RegistroSeguro.h"
#include <chrono>
#include <stdexcept>
#include <thread>

RouterWiFi::RouterWiFi(const std::string& id, int canales)
    : DispositivoComunicacion(id, "Router WiFi 6"),
      canalesActivos(canales) {
    if (canales < 0)
        throw std::invalid_argument("Canales WiFi negativos.");
}

void RouterWiFi::transmitir() {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    registrarEventoSeguro("Router " + id +
        ": trama WiFi de 5 GHz; canales activos: " +
        std::to_string(canalesActivos));
}
