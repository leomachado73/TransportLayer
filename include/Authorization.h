//
// Created by machado on 13/03/19.
//

#ifndef OPCODEHANDLER_AUTHORIZATION_H
#define OPCODEHANDLER_AUTHORIZATION_H

#include "Middleware.h"
#include "Player.h"
#include "WorldPacket.h"


class Authorization : public Middleware
{
public:
    Authorization()
    {}

    Authorization(Authorization const &other)
    {}

    ~Authorization()
    {
    }

    bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) override;


};

#endif //OPCODEHANDLER_AUTHORIZATION_H
