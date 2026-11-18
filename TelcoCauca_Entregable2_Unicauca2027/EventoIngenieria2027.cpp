#include "EventoIngenieria2027.h"
#include "RegistroSeguro.h"
#include <exception>
#include <string>

void mostrarAgenda2027(const std::vector<EventoIngenieria2027>& agenda) {
    try {
        registrarEventoSeguro("AGENDA UNICAUCA 2027 - BICENTENARIO");
        for (const auto& evento : agenda) {
            registrarEventoSeguro(
                evento.nombre + " | Area: " + evento.area +
                " | Periodo: " + evento.periodo +
                " | Estado: " + evento.estado +
                " | Fuente: " + evento.fuente);
        }
    } catch (const std::exception& e) {
        registrarEventoSeguro(std::string("ERROR EN AGENDA: ") + e.what());
    }
}
