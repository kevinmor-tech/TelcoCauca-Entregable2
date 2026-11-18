#ifndef ITRANSMISIBLE_H
#define ITRANSMISIBLE_H

// Interfaz pura trabajada en la Unidad 7.
class ITransmisible {
public:
    virtual void transmitir() = 0;
    virtual ~ITransmisible() {}
};

#endif
