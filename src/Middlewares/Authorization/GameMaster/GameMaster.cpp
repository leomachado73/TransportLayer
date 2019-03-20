//
// Created by machado on 14/03/19.
//

#include "GameMaster.h"
#include <typeinfo>

bool GameMaster::validate(const Permission *permission)
{
    return permission ? typeid(*permission) == typeid(GameMaster) : false;
}

const std::string GameMaster::getName() const
{
    return std::string("GameMaster");
}
