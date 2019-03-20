
#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "Player.h"
#include "WorldPacket.h"
//#include "OpcodeHandler.h"

class OpcodeHandler;

class Middleware
{

private:
    Middleware *next;

public:
    Middleware()
    {
        next = nullptr;
    }

    virtual ~Middleware()
    {
        if(next)
        {
            delete next;
            next = nullptr;
        }
    }

    void append(Middleware *node)
    {
        Middleware *q = this;

        while (q->hasNext())
        {
            q = q->getNext();
        }

        q->setNext(node);
    }

    void setNext(Middleware *node)
    {
        this->next = node;
    }

    Middleware *getNext() const
    {
        return this->next;
    }

    bool hasNext() const
    {
        return getNext() != nullptr;
    }

    virtual bool process(Player *issuer, WorldPacket *request, const OpcodeHandler *target) = 0;
};


#endif //MIDDLEWARE_H
