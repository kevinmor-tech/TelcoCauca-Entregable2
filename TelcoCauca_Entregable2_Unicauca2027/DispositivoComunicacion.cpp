#include "DispositivoComunicacion.h"

DispositivoComunicacion::DispositivoComunicacion(
    const std::string& id, const std::string& tipo)
    : id(id), tipo(tipo) {}

DispositivoComunicacion::~DispositivoComunicacion() {}

std::string DispositivoComunicacion::getId() const {
    return id;
}

std::string DispositivoComunicacion::getTipo() const {
    return tipo;
}
