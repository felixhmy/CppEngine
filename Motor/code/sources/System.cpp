// Realizado por: Félix Hernández Muñoz - Yusta

#include "System.hpp"

namespace engine
{


    RenderSystem::RenderSystem (Scene * scene) : RenderSystem (scene)
    {
        renderer = make_shared<glt::Render_Node>();

        auto camera = make_shared<glt::Camera>(1, 1, 1, 1);
        renderer.add("camera", camera);
        camera->translate(glt::Vector3(0, 0, 0));


        auto light = make_shared<glt::Light>();
        renderer.add("light", light);
        light->translate(glt::Vector3(0, 0, 1));
    }


    shared_ptr <Component> RenderSystem::create_component(const Entity& entity, const std::string& component_id)
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
            //component->owner = &entity;

            //model->set_postion(glt::Vector3(0, 0, 1));
            //components.push_back(component);
        }
        else 
        {
            return nullptr;
        }
        return component;
    }
}