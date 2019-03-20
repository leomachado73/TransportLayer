//
// Created by machado on 14/03/19.
//

#ifndef OPCODEHANDLER_GAMEMASTER_H
#define OPCODEHANDLER_GAMEMASTER_H

#include "Permission.h"


class GameMaster : public Permission
{
public:
    GameMaster()
    {
    }

    ~GameMaster()
    {
    }

    bool validate(const Permission *permission) override;

    const std::string getName() const override;
};


#endif //OPCODEHANDLER_GAMEMASTER_H
