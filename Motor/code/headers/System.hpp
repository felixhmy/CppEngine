// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "Task.hpp"
#include "Component.hpp"
#include "Entity.hpp"

#include <list>
#include <memory>

#include "Model_Obj.hpp"
#include "Render_Node.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "Cube.hpp"
#include "Model.hpp"


namespace engine
{
    class System : public Task 
    {
    public:
        virtual std::shared_ptr<Component> create_component(Entity& entity, const std::string& component_id) = 0;
    };


    class RenderTask : public System
    {
        
        list<shared_ptr<Component>> components;
        glt::Render_Node renderer;
        //shared_ptr <glt::Render_Node> renderer;

    public:
        RenderTask(Scene* scene);
        shared_ptr<Component> create_component(Entity & entity, const std::string& component_id) override;
        

        void execute(float t) override;
    };
}