#include "TransportLayer.h"
#include "Player.h"
#include "WorldPacket.h"
#include "Middleware.h"
#include "Opcodes.h"
#include "OpcodeHandler.h"
#include "Test1.h"
#include "Test2.h"
#include "LoginHandler.h"
#include "InvokeHandler.h"

TransportLayer::TransportLayer()
{
    globalMiddlewares = nullptr;
    handlers.clear();

    initialize();
}

TransportLayer::~TransportLayer()
{
    if(globalMiddlewares)
    {
        delete globalMiddlewares;
        globalMiddlewares = nullptr;
    }

    handlers.clear();
}

void TransportLayer::initialize()
{
    create(OpCode::MSG_ID_GETUSERINFO)
            .name("MSG_ID_GETUSERINFO")
            .summary("Authenticate User")
            .description("Authenticate and send channel server to the client.")
            .authorizations(new GameMaster(), new Administrator())
            .handlers(new Test1(), new Test2(), new LoginHandler());

}

bool TransportLayer::process(Player *issuer, WorldPacket *request)
{
    const OpcodeHandler *handler = this->get(request->getOpcode());

    if (globalMiddlewares)
    {
        return globalMiddlewares->process(issuer, request, handler);

    } else
    {
        return handler->handlers()->process(issuer, request, handler);
    }
}

