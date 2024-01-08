// Realizado por: Félix Hernández Muñoz - Yusta

#include "Scene.hpp"
#include "internal/Window.hpp"

namespace engine
{
    Scene::Scene() : RenderSystem(this) 
    {
        window = new Window (name, width, height, full);
        kernel.add(input_task);
        kernel.add(render_task);

        load_scene();
    }

    Window& Scene::get_window() 
    {
        return *window;
    }

    Window& Scene::swap_buffers()
    {

    }

    void Scene::run() 
    {
        kernel.run();
    }

    void Scene::load_scene() 
    {

    }
}




