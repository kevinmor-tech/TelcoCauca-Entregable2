#ifndef REGISTRO_SEGURO_H
#define REGISTRO_SEGURO_H
#include <string>

// Consola compartida y contador protegido: un mutex, RAII.
void registrarEventoSeguro(const std::string& mensaje);
void registrarTransmisionExitosa();
void registrarTransmisionFallida();
void mostrarResumenSeguro();

#endif
