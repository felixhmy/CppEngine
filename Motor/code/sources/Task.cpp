// Realizado por: Félix Hernández Muñoz - Yusta

#include "Task.hpp"

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
                KeyPress(event.key.keysym.sym);
            }
        }
    }


    void InputTask::KeyPress(SDL_Keycode key) 
    {
        // Falta el encapsularlo para que pase a traves de la clase Keyboard para que a la hora de usarlo en la Demo, se usen las de Keyboard
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


    RenderTask::RenderTask(Scene* scene) : Task(scene) 
    {
        renderer = make_shared<glt::Render_Node>();

        //Crear camara
        auto camera = make_shared<glt::Camera>(1, 1, 1, 1);
        // Añadir al renderer
        renderer->add("camera", camera);
        //Darle una posición
        camera->translate(glt::Vector3(0,0,0));

        //Crear luz
        auto light = make_shared<glt::Light>();
        //Añadirla al renderer
        renderer->add("light", light);
        //Darle una posición
        light->translate(glt::Vector3(0, 0, 1));
    }

    // Se llama desde System
    shared_ptr<Component> RenderTask::create_component(const std::string & modelPath) 
    {
        // Crear un componente
        auto component = make_shared<Model_Component>();
        // Añadirle un modelo en 3D
        //auto model = make_shared <glt::Model_Obj>(modelPath);
        component->model = shared_ptr<Model>(new Model_Obj(modelPath));
        
        // Asignarle un ID unico para el objeto
        /// Normalmente se pone le asocia el ID de su propio componente
        renderer->add("ID-de-componente-unico", component->model);
        //Se le da una posición
        model->set_postion(glt::Vector3(0, 0, 1));
        // Se añade en la list de components
        components.push_back(component);

        return component;
    }

    void RenderTask::execute(float t) 
    {
        cout << "Rendering" << endl;

        for (auto& component : components) 
        {
            glm::mat4 transform_matrix = component->owner->get_transform().get_matrix();
            //component->model->set_transformation(transform_matrix);
        }

        renderer->render();

        scene->get_window()->swap_buffers();
    }
}
