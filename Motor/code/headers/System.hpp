// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "Task.hpp"

#include <list>
#include <memory>

namespace glt { class Render_Node; }

namespace engine
{
    class Component;
    class Entity;
    class Scene;

    class System : public Task 
    {
    public:
        System(Scene* scene) : Task(scene){}

        virtual std::shared_ptr<Component> create_component(Entity& entity, const std::string& component_id) = 0;
    };


    class RenderSystem : public System
    {
        
        list<shared_ptr<Component>> components;
        unique_ptr<glt::Render_Node> renderer;

    public:
        RenderSystem(Scene* scene);
        shared_ptr<Component> create_component(Entity & entity, const std::string& component_id) override;
        ~RenderSystem();
        

        void execute(float t) override;
    };
}