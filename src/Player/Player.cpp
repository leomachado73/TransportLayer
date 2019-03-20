#include "Player.h"


Player::Player()
{
}

Player::~Player()
{
    delete permission;
    permission = nullptr;
}


const std::string &Player::getUsername() const
{
    return username;
}

void Player::setUsername(const std::string &username)
{
    Player::username = username;
}

const std::string &Player::getPassword() const
{
    return password;
}

void Player::setPassword(const std::string &password)
{
    Player::password = password;
}

Permission *Player::getPermission() const
{
    return permission;
}

void Player::setPermission(Permission *permission)
{
    Player::permission = permission;
}




