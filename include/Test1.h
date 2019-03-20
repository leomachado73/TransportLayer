#ifndef TEST1_H
#define TEST1_H

#include "Player.h"
#include "WorldPacket.h"
#include "Middleware.h"
#include <iostream>

using namespace std;


class Test1 : public Middleware
{
public:
    Test1()
    {
    }

    virtual ~Test1()
    {
    }

    bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) override
    {
        cout << "Test1" << endl;

        return getNext()->process(issuer, request, target);
    }
};

#endif //TEST1_H
