#include "pch.hpp"

#include "TradeStatus.hpp"

void on::TradeStatus(ENetPeer *peer) 
{
    ::peer *pPeer = static_cast<::peer*>(peer->data);

    std::string add_slots;
    for (const ::slot &slot : pPeer->trade_offers)
    {
        add_slots += std::format("add_slot|{}|{}\n", slot.id, slot.count);
    }
    send_varlist(peer, {
        "OnTradeStatus",
        pPeer->netid,
        "",
        std::format("`o{}'s offer.``", pPeer->display_growid),
        std::format(
            "{}"
            "locked|{}\n"
            "reset_locks|{}\n"
            "accepted|{}\n", 
            add_slots, "0", "1", pPeer->trade_accepted) // @todo complete this later...
        }
    );
}
