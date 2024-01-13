// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include <map>
#include <string>
#include <memory>

#include "Component.hpp"

namespace engine
{
    class Entity 
    {
        std::map<std::string, std::shared_ptr<Component>> components;

        Transform_Component transform;


    public:
        void add(const std::string& id, std::shared_ptr<Component> component);

        auto& get_transform()
        {
            return transform;
        }

        Component* get_component_by_id(const std::string& id);
    };

}