// Autor: felixhmy 
// Todos los derechos reservados © 2025 

#pragma once

#include <iostream>
#include <memory>
#include <list>

using namespace std;

namespace engine 
{
    class Scene;
    // Tarea "padre" de la que heredan el resto de tareas.
    class Task 
    {
    protected:
        Scene* scene;

    public:
        Task(Scene* scene) : scene(scene) {}
        virtual void execute(float t) = 0;
    };

    // Input del usuario
    class InputTask : public Task 
    {
    public:
        InputTask(Scene* scene);
        void execute(float t) override;

    private:
       void KeyPress(int key);
    };
}
