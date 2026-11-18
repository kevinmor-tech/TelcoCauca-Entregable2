#include "GatewayLoRa.h"
#include "RegistroSeguro.h"
#include <chrono>
#include <sstream>
#include <stdexcept>
#include <thread>

GatewayLoRa::GatewayLoRa(const std::string& id, float frecuencia)
    : DispositivoComunicacion(id, "Gateway LoRaWAN"),
      frecuenciaMHz(frecuencia) {
    if (!(frecuencia > 0.0f))
        throw std::invalid_argument("Frecuencia LoRa invalida.");
}

void GatewayLoRa::transmitir() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::ostringstream msg;
    msg << "Gateway " << id << ": enlace LoRa de "
        << frecuenciaMHz << " MHz";
    registrarEventoSeguro(msg.str());
}
