#pragma once

#include <unordered_map>
#include <functional>

extern std::unordered_map<std::string, std::function<void(ENetEvent &, const ::hPipe &)>> dialog_return_pool;
