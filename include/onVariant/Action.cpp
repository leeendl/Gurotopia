#include "pch.hpp"

#include "Action.hpp"

void on::Action(ENetEvent& event, const std::string_view text) 
{
    ::peer *pPeer = static_cast<::peer*>(event.peer->data);

    std::string_view to_slang = 
        (text == "facepalm") ? "fp" : 
        (text == "shrug") ? "idk" : 
        (text == "foldarms") ? "fold" : 
        (text == "fa") ? "fold" : 
        (text == "stubborn") ? "fold" : text;

    const std::string &action = ('/' + std::string(to_slang));
    peers(pPeer->recent_worlds.back(), PeerSearch::WORLD, [&pPeer, &action](ENetPeer *peer)
    {
        send_varlist(peer, { "OnAction", action }, pPeer->netid);
    });
}
