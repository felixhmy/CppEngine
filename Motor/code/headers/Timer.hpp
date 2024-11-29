#pragma once

#include <chrono>

namespace engine
{
    // Se encarga de gestionar el tiempo dentro del motor.
    class Timer
    {
    private:
        std::chrono::high_resolution_clock::time_point start;

    public:
        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        // Reinicia el tiempo.
        void reset()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        // Devuelve el tiempo transcurrido desde el inicio.
        float get_elapsed_seconds() const
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            return duration.count() / 1000.0f;
        }
    };
}
