// Realizado por: Félix Hernández Muñoz-Yusta

#pragma once

#include <chrono>

namespace engine
{
    class Timer
    {
    private:
        std::chrono::high_resolution_clock::time_point start;

    public:
        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        void reset()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        float get_elapsed_seconds() const
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            return duration.count() / 1000.0f;
        }
    };
}
