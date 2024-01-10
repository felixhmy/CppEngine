// Realizado por: Félix Hernández Muñoz - Yusta

#include "Task.hpp"
#include <SDL.h>

namespace engine 
{
    InputTask::InputTask(Scene* scene) : Task(scene) {}

    void InputTask::execute(float t) 
    {
        
        SDL_Event event;

        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_KEYDOWN) 
            {
                //KeyPress(event.key.keysym.sym);
            }
        }
    }

    /*
    void InputTask::KeyPress(SDL_Keycode key) 
    {
        switch (key) 
        {
        case Keyboard::KEY_W:
            // ARRIBA
            break;
        case Keyboard::KEY_S:
            // ABAJO
            break;
        case Keyboard::KEY_A:
            // IZQUIERDA
            break;
        case Keyboard::KEY_D:
            // DERECHA
            break;
        }
    }
    */
}
