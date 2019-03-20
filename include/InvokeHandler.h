//
// Created by machado on 14/03/19.
//

#ifndef INVOKE_AHANDLER_H
#define INVOKE_AHANDLER_H

#include "Middleware.h"
#include "Player.h"
#include "WorldPacket.h"
#include "OpcodeHandler.h"


// This class is the last node in the chain
// If the process reached this class, then proceed to the Opcode Handler

class InvokeHandler : public Middleware
{
public:
    bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) override;
};

#endif //INVOKE_HANDLER_H
