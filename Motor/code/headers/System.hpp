// Autor: felixhmy

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

    // Se encarga de gestionar los componentes de las entidades.
    class System : public Task 
    {
    public:
        System(Scene* scene) : Task(scene){}
        // Crea un componente para una entidad específica.
        virtual std::shared_ptr<Component> create_component(Entity& entity, const std::string& component_id) = 0;
    };

    //  Sistema que se encarga de renderizar los modelos de las entidades.
    class RenderSystem : public System
    {
        list<shared_ptr<Component>> components;
        unique_ptr<glt::Render_Node> renderer;
        
    public:

        int next_entity_id;
        std::string model_path;
        std::string entity_id;

        RenderSystem(Scene* scene);
        shared_ptr<Component> create_component(Entity & entity, const std::string& component_id) override;
        ~RenderSystem();
        

        void execute(float t) override;
    };
}
