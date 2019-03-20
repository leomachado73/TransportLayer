#ifndef PERMISSION_H
#define PERMISSION_H

#include <string>

class Permission
{
public:
    Permission();

    virtual ~Permission();

    virtual bool validate(const Permission *permission) = 0;
    virtual const std::string getName() const = 0;

};

#endif //PERMISSION_H
