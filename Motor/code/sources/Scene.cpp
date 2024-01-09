// Realizado por: Félix Hernández Muñoz - Yusta

#include "Scene.hpp"
#include "internal/Window.hpp"

namespace engine
{
    Scene::Scene(Window& window, const std::string& scene_file_path) // : RenderTask(this) 
    {
        kernel.add(input_task);
        kernel.add(render_task);
        kernel.add(update_task);

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




