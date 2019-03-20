//
// Created by machado on 13/03/19.
//

#ifndef OPCODEHANDLER_ADMINISTRATOR_H
#define OPCODEHANDLER_ADMINISTRATOR_H

#include "Permission.h"

class Administrator : public Permission
{
public:
    Administrator()
    {
    }

    ~Administrator()
    {
    }

    const std::string getName() const override;

    bool validate(const Permission *permission) override;

};


#endif //OPCODEHANDLER_ADMINISTRATOR_H
