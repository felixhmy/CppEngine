// Realizado por: Félix Hernández Muñoz-Yusta

#pragma once

#include <iostream>
#include <memory>
#include <list>

//#include "Scene.hpp"
//#include "System.hpp"
//#include "Entity.hpp"
//#include "Component.hpp"
//#include "internal/Keyboard.hpp"


using namespace std;

namespace engine 
{
    class Scene;
    // Tarea "padre"
    class Task 
    {
    protected:
        Scene* scene;

    public:
        Task(Scene* scene) : scene(scene)
        {}
        virtual void execute(float t) = 0;
    };

    // Input del usuario
    class InputTask : public Task 
    {
    public:
        InputTask(Scene* scene);
        void execute(float t) override;

    private:
       // void KeyPress(SDL_Keycode key);
    };
}
