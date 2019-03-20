#ifndef TRANSPORT_LAYER_H
#define TRANSPORT_LAYER_H

#include <map>

#include "OpcodeHandler.h"
#include "Middleware.h"
#include "InvokeHandler.h"
#include "Player.h"
#include "WorldPacket.h"




typedef std::map<OpCode, OpcodeHandler> HandlersPtr;

class TransportLayer
{
private:
    Middleware* globalMiddlewares;
    HandlersPtr handlers;


public:
    TransportLayer();

    virtual ~TransportLayer();

    void initialize();

    const OpcodeHandler *get(const OpCode &index)
    {
        return &handlers[index];
    }

    OpcodeHandler &create(const OpCode &index)
    {
        return handlers[index];
    }


    void use(Middleware* handler)
    {
        if (!globalMiddlewares)
        {
            globalMiddlewares = new InvokeHandler();

            use(handler);
        }
        else
        {
            handler->setNext(globalMiddlewares);

            globalMiddlewares = handler;
        }
    }

    bool process(Player *issuer, WorldPacket *request);
};


#endif //TRANSPORT_LAYER_H

