// Realizado por: Félix Hernández Muñoz - Yusta

#include "System.hpp"

namespace engine
{


    RenderTask::RenderTask(Scene * scene) : RenderTask(scene)
    {
    }


    shared_ptr <Component> RenderTask::create_component(Entity& entity, const std::string& component_id)
    {

        shared_ptr <Component> component;

        if (component_id == "model")
        {
            // TIENE QUE HABER UNA SOLA PARA CADA MODEL
            std::string model_path = "ruta-del-archivo";
            std::string entity_id = "id-de-componente-unico"; //HAY QUE SACARLA DE LA PROPIA ENTIDAD

            auto model = make_shared <glt::Model_Obj>(model_path);

            renderer.add(entity_id, model);

            auto model_component = make_shared <Model_Component>();

            model_component->model = model;

            component = model_component;
            component->owner = &entity;

            //components.push_back(component);
        }
        else if (component_id == "camera")
        {
            auto camera = make_shared<glt::Camera>(1, 1, 1, 1);
            renderer.add("camera", camera);
            camera->translate(glt::Vector3(0, 0, 0));
        }
        else if (component_id == "light")
        {
            auto light = make_shared<glt::Light>();
            renderer.add("light", light);
            light->translate(glt::Vector3(0, 0, 1));
        }
        return component;
    }

    void RenderTask::execute(float t)
    {
        for (auto& component : components)
        {
            glm::mat4 transform_matrix = component->owner->get_transform()->get_matrix();

            auto model_component = dynamic_cast <Model_Component*> (component.get());
            auto camera_component = dynamic_cast <Camera_Component*> (component.get());
            auto light_component = dynamic_cast <Light_Component*> (component.get());

            if (model_component)
            {
                model_component->model->set_transformation(transform_matrix);
            }
            else if (camera_component)
            {
                camera_component->camera->set_transformation(transform_matrix);
            }
            else if (light_component)
            {
                light_component->light->set_transformation(transform_matrix);
            }
        }
        renderer.render();
        
        Window& window = scene->get_window();
        window.swap_buffers();
    }
}