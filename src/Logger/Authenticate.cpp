//
// Created by machado on 12/03/19.
//

#include "Authenticate.h"
#include <iostream>

using namespace std;

Authenticate::Authenticate()
{}

Authenticate::~Authenticate()
{}

bool Authenticate::handleAuthenticateMessage(Player *player, WorldPacket *packet, const OpcodeHandler *target)
{
    cout << "Authenticate Message" << endl;

    cout << "Player info: " << endl;
    cout << player->getUsername() << endl;
    cout << player->getPassword() << endl;
}

bool Authenticate::process(Player *issuer, WorldPacket *request, const OpcodeHandler *target)
{

    return handleAuthenticateMessage(issuer, request, target);
}


