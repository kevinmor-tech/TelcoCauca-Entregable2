#ifndef DISPOSITIVO_COMUNICACION_H
#define DISPOSITIVO_COMUNICACION_H

#include "ITransmisible.h"
#include <string>

// Base abstracta: todos los dispositivos cumplen ITransmisible.
class DispositivoComunicacion : public ITransmisible {
protected:
    std::string id;
    std::string tipo;

public:
    DispositivoComunicacion(const std::string& id,
                           const std::string& tipo);
    virtual ~DispositivoComunicacion();
    virtual void transmitir() = 0;
    std::string getId() const;
    std::string getTipo() const;
};

#endif
