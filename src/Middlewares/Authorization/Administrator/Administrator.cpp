//
// Created by machado on 13/03/19.
//

#include "Administrator.h"
#include <typeinfo>

bool Administrator::validate(const Permission *permission)
{
    return permission ? typeid(*permission) == typeid(Administrator) : false;
}

const std::string Administrator::getName() const
{
    return std::string("Administrator");
}
