#ifndef WORLD_PACKET_H
#define WORLD_PACKET_H

#include "Opcodes.h"

class WorldPacket
{
private:
    OpCode opcode;

public:
    WorldPacket();
    WorldPacket(OpCode opcode);
    ~WorldPacket();

    OpCode getOpcode() const;

    void setOpcode(OpCode opcode);
};


#endif // WORLD_PACKET_H
