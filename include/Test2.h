#ifndef TEST2_H
#define TEST2_H

#include "Player.h"
#include "WorldPacket.h"
#include "Middleware.h"
#include <iostream>

using namespace std;

class Test2 : public Middleware
{
public:
    Test2()
    {}

    virtual ~Test2()
    {}

    bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) override
    {
        cout << "Test2" << endl;

        return getNext()->process(issuer, request, target);
    }
};

#endif //TEST2_H
