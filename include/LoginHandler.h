#ifndef LOGIN_HANDLER_H
#define LOGIN_HANDLER_H

#include "Middleware.h"
#include "Player.h"
#include "WorldPacket.h"
#include "OpcodeHandler.h"

#include <iostream>

using namespace std;

class LoginHandler : public Middleware
{
public:
    LoginHandler(){}
    virtual ~LoginHandler(){}

    bool handleLoginMessage(Player *player, WorldPacket *packet, const OpcodeHandler *target)
    {
        cout << "handleLoginMessage" << endl;

        return true;
    }

    bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) override
    {
        return handleLoginMessage(issuer, request, target);
    }
};

#endif //LOGIN_HANDLER_H
