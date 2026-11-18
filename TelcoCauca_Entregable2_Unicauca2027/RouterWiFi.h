#ifndef ROUTER_WIFI_H
#define ROUTER_WIFI_H
#include "DispositivoComunicacion.h"

class RouterWiFi : public DispositivoComunicacion {
private:
    int canalesActivos;

public:
    RouterWiFi(const std::string& id, int canales);
    void transmitir() override;
};
#endif
