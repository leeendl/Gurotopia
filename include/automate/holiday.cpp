#include "pch.hpp"

#include "holiday.hpp"

::holiday active_holiday = holiday::NO_ACTIVE;

std::tm localtime()
{
    std::time_t now  = std::time(nullptr);

    return *std::localtime(&now);
}

void check_for_holiday()
{
    std::tm time = localtime();

    if      (time.tm_mon == 1/*feb*/   && (time.tm_mday >= 13 && time.tm_mday <= 13+7)) active_holiday = holiday::VALENTINES;
    else if (time.tm_mon == 2/*march*/ && (time.tm_mday >= 14 && time.tm_mday <= 14+7)) active_holiday = holiday::PATRICKS;
    else if (time.tm_mon == 4/*may*/   && (time.tm_mday >=  5 && time.tm_mday <= 5+7)) active_holiday = holiday::CINCO_DE_MAYO;
    else if (time.tm_mon == 6/*july*/  && (time.tm_mday >= 10 && time.tm_mday <= 10+7)) active_holiday = holiday::SUMMERFEST;
    else if (time.tm_mon == 9/*oct*/   && (time.tm_mday >= 23 && time.tm_mday <= 23+7)) active_holiday = holiday::HALLOWEEN;
}

std::string game_theme_string()
{
    switch (active_holiday)
    {
        case holiday::VALENTINES:    return "valentines-theme";
        case holiday::PATRICKS:      return "patricks-theme";
        case holiday::CINCO_DE_MAYO: return "cinco-theme";
        case holiday::SUMMERFEST:    return "summerfest-theme";
        case holiday::G4G:           return "g4g-theme";
    }
    return ""; // @note default:
}

std::pair<std::string, std::string> holiday_greeting()
{
    switch (active_holiday)
    {
        case holiday::VALENTINES: return {"`5Valentine's Week!``",   "`4Happy Valentine's Week!``"};
        case holiday::PATRICKS:   return {"`5St. Patrick's Week!``", "`2Happy St. Patrick's Day!``"};
        case holiday::CINCO_DE_MAYO: return {"Cinco De Mayo Week``", "`3It's Approximately `2Cinco `wDe `4Mayo!`` Party with your friends and smash Piñatas for prizes!``"};
        case holiday::SUMMERFEST: return {"`5Summerfest``",          "`3Party down, it's `4Summerfest!`` Collect Fireworks and celebrate!``"};
        case holiday::HALLOWEEN:  return {"`5Halloween``", "`6It's `4Halloween!`` Visit the world `4GROWGANOTH`` to sacrifice your items to Almighty Growganoth!``"};
        case holiday::G4G:        return {"`5Grow4Good Week!``",     "It's `2Grow4Good!`` Complete tasks, earn rewards and contribute to a great cause!"};
    }
    return {"", ""};  // @note default:
}

std::string holiday_banner()
{
    switch (active_holiday)
    {
        case holiday::VALENTINES: return "interface/large/gui_valentine_banner.rttex";
        case holiday::CINCO_DE_MAYO: return "interface/large/news_banner_split.rttex"; //@todo this could be due to 2 active events going on
    }
    return "interface/large/news_banner.rttex"; // @note default:
}