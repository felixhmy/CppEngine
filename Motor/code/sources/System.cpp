// Realizado por: Félix Hernández Muñoz - Yusta

#include "System.hpp"
#include "Component.hpp"
#include "Entity.hpp"
#include "internal/Window.hpp"
#include "Scene.hpp"


#include <Model_Obj.hpp>
#include <Light.hpp>
#include <Camera.hpp>
#include <Cube.hpp>
#include <Model.hpp>
#include <Render_Node.hpp>

using namespace glt;

namespace engine
{


    RenderTask::RenderTask(Scene * scene) : System (scene)
    {
        renderer = make_unique < Render_Node>();

        auto camera = make_shared<glt::Camera>(10, 0.1f, 1000.f, 1.333f);
        renderer->add("camera", camera);
        camera->translate(glt::Vector3(0, 0, 0));

        auto light = make_shared<glt::Light>();
        renderer->add("light", light);
        light->translate(glt::Vector3(50, 50, 50));
    }

    RenderTask::~RenderTask() {}

    shared_ptr <Component> RenderTask::create_component(Entity& entity, const std::string& component_id)
    {

        shared_ptr <Component> component;

        if (component_id == "model")
        {
            std::string model_path = "../../Demo/binaries/Robot.obj";
            // ASIGNARLE EL ID DE LA ENTIDAD QUE SE SACA DEL XML Y QUE DEBERIA RECIBIR ESTA FUNCIÓN POR PARAMETRO (entity_id)
            std::string entity_id = "entity_id-cambiar";

            auto model = make_shared <glt::Model_Obj>(model_path);

            renderer->add(entity_id, model);

            auto model_component = make_shared <Model_Component>();

            model_component->model = model;

            component = model_component;
            component->owner = &entity;

            //components.push_back(component);
        }
        return component;
    }

    void RenderTask::execute(float t)
    {
        for (auto& component : components)
        {
            glm::mat4 transform_matrix = component->owner->get_transform().get_matrix();

            auto model_component = dynamic_cast <Model_Component*> (component.get());
  

            if (model_component)
            {
                model_component->model->set_transformation(transform_matrix);
            }
        }
        scene->get_window().clear();

        renderer->render();
        
        scene->get_window().swap_buffers();
    }
}