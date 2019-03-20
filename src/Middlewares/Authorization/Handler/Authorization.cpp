#include "Authorization.h"
#include "Player.h"
#include "WorldPacket.h"
#include "TransportLayerException.h"
#include "OpcodeHandler.h"

#include <iostream>

using namespace std;

bool Authorization::process(Player *issuer, WorldPacket *request, const OpcodeHandler *target)
{
    if (issuer && request && target)
    {
        for (auto &authorization : target->getAuthorizations())
        {
            // User has authorization to go ahead?
            if (authorization->validate(issuer->getPermission()))
            {

                cout << "User authorized" << endl;


                // Check if there's a next middleware
                if (this->hasNext())
                    return getNext()->process(issuer, request, target);
            }
        }
    }

    return false;
}


