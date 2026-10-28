#pragma once

#include <unordered_map>
#include <functional>

extern std::unordered_map<ENetEventType, std::function<void(ENetEvent&)>> eventType_pool;
