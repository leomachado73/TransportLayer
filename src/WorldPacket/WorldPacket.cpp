//
// Created by machado on 12/03/19.
//

#include "WorldPacket.h"

WorldPacket::WorldPacket()
{
    setOpcode(OpCode::MSG_NULL);
}

WorldPacket::~WorldPacket()
{
}

OpCode WorldPacket::getOpcode() const
{
    return opcode;
}

void WorldPacket::setOpcode(OpCode opcode)
{
    WorldPacket::opcode = opcode;
}

WorldPacket::WorldPacket(OpCode opcode)
{
    setOpcode(opcode);

}


