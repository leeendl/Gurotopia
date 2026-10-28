#include "pch.hpp"

#include "onVariant/TradeStatus.hpp"

#include "rem_trade.hpp"

void action::rem_trade(ENetEvent& event, const std::string& header) 
{
    ::peer *pPeer = static_cast<::peer*>(event.peer->data);

    const std::string &itemID = readch(header, '|')[3];

    for (auto it = pPeer->trade_offers.begin(); it != pPeer->trade_offers.end(); ++it)
    {
        if (it->id == atoi(itemID.c_str()))
        {
            pPeer->trade_offers.erase(it);
            break;
        }
    }
    on::TradeStatus(event.peer);
}