#include "pch.hpp"
#include "respawn_spike.hpp"

void action::respawn_spike(ENetEvent& event, const std::string& header) 
{
    ::peer *pPeer = static_cast<::peer*>(event.peer->data);

    send_varlist(event.peer, { "OnSetFreezeState", 2 }, pPeer->netid);
    send_varlist(event.peer, { "OnKilled"}, pPeer->netid);
    send_varlist(event.peer, {
        "OnSetPos", 
        CL_Vec2f{pPeer->rest_pos.x, pPeer->rest_pos.y}
    }, pPeer->netid, 0);
    send_varlist(event.peer, { "OnSetFreezeState"}, pPeer->netid, 0);
}