#ifndef EVENTO_INGENIERIA_2027_H
#define EVENTO_INGENIERIA_2027_H
#include <string>
#include <vector>

// Actividades verificadas y propuestas se identifican por su estado.
struct EventoIngenieria2027 {
    std::string nombre;
    std::string area;
    std::string periodo;
    std::string estado;
    std::string fuente;
};

// El vector viaja por referencia constante (std::cref en main).
void mostrarAgenda2027(const std::vector<EventoIngenieria2027>& agenda);

#endif
