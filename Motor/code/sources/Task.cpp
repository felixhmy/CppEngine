// Realizado por: Félix Hernández Muñoz - Yusta

#include "Task.hpp"
#include "internal/Keyboard.hpp"
#include "Scene.hpp"

#include <SDL.h>

namespace engine 
{
    InputTask::InputTask(Scene* scene) : Task(scene) {}

    // Ejecuta la tarea de input del usuario.
    void InputTask::execute(float t) 
    {

        SDL_Event event;

        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_KEYDOWN) 
            {
               KeyPress(event.key.keysym.sym);
            }else if (event.type == SDL_QUIT)
            {
                scene->stop();
            }

        }

    }

    // Detecta la tecla pulsada y realiza la acción correspondiente.

    void InputTask::KeyPress(int key) 
    {
        switch (key) 
        {
        case SDLK_w:
            // ARRIBA
            /// ENVIAR MENSAJE A TRAVES DE LA ESCENA
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
    
}
