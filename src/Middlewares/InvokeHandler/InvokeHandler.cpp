#include "InvokeHandler.h"



bool InvokeHandler::process(Player *issuer, WorldPacket *request, const OpcodeHandler *target)
{
    return target->handlers()->process(issuer, request, target);
}
