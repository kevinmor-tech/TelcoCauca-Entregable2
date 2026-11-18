#ifndef SWITCH_FIBRA_H
#define SWITCH_FIBRA_H
#include "DispositivoComunicacion.h"

class SwitchFibra : public DispositivoComunicacion {
private:
    int puertosActivos;

public:
    SwitchFibra(const std::string& id, int puertos);
    void transmitir() override;
};
#endif
