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

    Component* Entity::get_component_by_id(const std::string& id)
    {
        auto item = components.find (id);

        if (item != components.end())
        {
            return item ->second.get();
        }
		return nullptr;
	}
}