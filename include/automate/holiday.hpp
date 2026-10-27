#pragma once

enum class holiday : u_char
{
    NO_ACTIVE = 0,
    VALENTINES = 1,
    PATRICKS = 2,
    CINCO_DE_MAYO = 5,
    SUMMERFEST = 6,
    HALLOWEEN = 8,
    G4G = 18
};
extern ::holiday active_holiday;

extern std::tm localtime();

extern void check_for_holiday();

extern std::string game_theme_string();

extern std::pair<std::string, std::string> holiday_greeting();

extern std::string holiday_banner();
