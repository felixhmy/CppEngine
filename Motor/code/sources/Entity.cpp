// Realizado por: Félix Hernández Muñoz - Yusta

#include "Entity.hpp"

namespace engine
{
    void Entity::add(const std::string& id, std::shared_ptr<Component> component) 
    {
        components[id] = component;
        component->owner = this;
    }

    auto& Entity::get_transform() 
    {
        return transform;
    }

}