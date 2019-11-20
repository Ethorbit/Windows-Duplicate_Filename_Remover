#include "Wait.h"
#include <chrono>

Wait::Wait(int ms) {
	auto endTime = std::chrono::steady_clock::now() + std::chrono::milliseconds(ms);
	while (std::chrono::steady_clock::now() < endTime) {}
}