#include "pch.hpp"

#include "trade_started.hpp"

void action::trade_started(ENetEvent& event, const ::hPipe &hPipe)
{
    signed netid = atoi(hPipe["netid"].c_str());

}
