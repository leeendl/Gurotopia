#include "pch.hpp"

#include "ping_reply.hpp"

void ping_reply(ENetEvent& event, ::gamePacket gamePacket)
{
    ::peer *pPeer = static_cast<::peer*>(event.peer->data);
    
    print(std::format("ping requested from {}", pPeer->growid));
}