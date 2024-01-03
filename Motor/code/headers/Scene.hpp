// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "internal/Window.hpp"
#include "Entity.hpp"
#include "Task.hpp"
#include "System.hpp"
#include "Kernel.hpp"


#include <map>
#include <memory>
#include <string>

namespace engine
{
    class Scene 
    {

        Window* window;
        string name;
        unsigned width;
        unsigned height;
        bool full;



        std::map<std::string, std::shared_ptr<Entity>> entities; // Mapa de entidades

        Kernel kernel;

        InputTask input_task;

        RenderTask render_task;

        

    public:
        Scene();
        Window& get_window();
        void run();

    private:
        void load_scene();
    };
}





