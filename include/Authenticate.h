#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include "Middleware.h"
#include "Player.h"
#include "WorldPacket.h"
#include "OpcodeHandler.h"


class Authenticate : public Middleware
{
public:
    Authenticate();
    virtual ~Authenticate();

    bool handleAuthenticateMessage(Player *player, WorldPacket *packet, const OpcodeHandler *target);

    bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) override;
};

#endif //AUTHENTICATE_H
