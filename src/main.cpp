#include <iostream>     // std::cout
#include "TransportLayer.h"
#include "Authorization.h" // Global middleware
#include "Player.h"
#include "WorldPacket.h"
#include "InvokeHandler.h"

using namespace std;

int main()
{
    try
    {
        TransportLayer app;

        app.use(new Authorization());


        Player player = Player::create("admin", "123456", new GameMaster());

        WorldPacket worldPacket(OpCode::MSG_ID_GETUSERINFO);

        if (app.process(&player, &worldPacket))
        {
            cout << "Request accepted. " << endl;
        }
        else
        {
            cout << "Request denied" << endl;
        }

    }
    catch (TransportLayerException &ex)
    {
        cerr << "ERROR: " << ex.what() << endl;
    }
    catch (std::exception &ex)
    {
        cerr << ex.what() << endl;
    }


    return EXIT_SUCCESS;
}
