#ifndef GATEWAY_LORA_H
#define GATEWAY_LORA_H
#include "DispositivoComunicacion.h"

class GatewayLoRa : public DispositivoComunicacion {
private:
    float frecuenciaMHz;

public:
    GatewayLoRa(const std::string& id, float frecuencia);
    void transmitir() override;
};
#endif
