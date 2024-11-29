// Autor: felixhmy

#include "Kernel.hpp"
#include "Timer.hpp"

namespace engine
{
    // Añade una tarea a la lista.
    void Kernel::add(Task& task)
    {
        tasks.push_back(&task);
    }

    // Ejecuta un bucle continuamente hasta que se llama a stop.
    // En cada vuelta del bucle, todas las tareas se ejecutan.
    void Kernel::run()
    {
        exit = false;
        float time = 0.0f;

        do
        {
            Timer timer;

            for (auto task : tasks)
            {
                task->execute(time);
            }

            time = timer.get_elapsed_seconds();

        } while (!exit);
    }

    // Establece la salida para detener el bucle.
    void Kernel::stop()
    {
        exit = true;
    }
}
