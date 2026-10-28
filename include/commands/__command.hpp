#pragma once

#include <unordered_map>
#include <functional>

extern std::array<std::string_view, 6> cmd_requires_arg;

extern std::unordered_map<std::string_view, std::function<void(ENetEvent&, const std::string_view)>> cmd_pool;

