#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Permission.h"
#include "Permissions.h"

class Player
{
private:
    std::string username;
    std::string password;
    Permission* permission;

public:
    static Player create(std::string username, std::string password, Permission* permission)
    {
        Player player;

        player.setUsername(username);
        player.setPassword(password);
        player.setPermission(permission);

        return player;
    }

    Player();
    ~Player();

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    Permission *getPermission() const;

    void setPermission(Permission *permission);

public:

};


#endif //PLAYER_H
