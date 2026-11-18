#include "RegistroSeguro.h"
#include <iostream>
#include <mutex>
#include <thread>

namespace {
    std::mutex mtxCompartido;
    int exitos = 0;
    int errores = 0;
}

void registrarEventoSeguro(const std::string& mensaje) {
    std::lock_guard<std::mutex> lock(mtxCompartido);
    std::cout << "[HILO " << std::this_thread::get_id() << "] "
              << mensaje << std::endl;
}

void registrarTransmisionExitosa() {
    std::lock_guard<std::mutex> lock(mtxCompartido);
    ++exitos;
}

void registrarTransmisionFallida() {
    std::lock_guard<std::mutex> lock(mtxCompartido);
    ++errores;
}

void mostrarResumenSeguro() {
    std::lock_guard<std::mutex> lock(mtxCompartido);
    std::cout << "RESUMEN | transmisiones exitosas: " << exitos
              << " | errores controlados: " << errores << std::endl;
}
