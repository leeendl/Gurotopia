#include "pch.hpp"

#include "respawn.hpp"

void action::respawn(ENetEvent& event, const std::string& header) 
{
    ::peer *pPeer = static_cast<::peer*>(event.peer->data);

    send_varlist(event.peer, { "OnSetFreezeState", 2u }, pPeer->netid);
    send_varlist(event.peer, { "OnKilled"}, pPeer->netid);

    send_varlist(event.peer, { "OnSetPos", CL_Vec2f{pPeer->rest_pos.x, pPeer->rest_pos.y} }, pPeer->netid, 0x000007d0/*2000ms*/);
    /* audio/teleport.wav */ // delay: 0x000007e4 (2020ms)
    send_varlist(event.peer, { "OnSetFreezeState", 0u }, pPeer->netid, 0x000007e4/*2020ms*/);
}