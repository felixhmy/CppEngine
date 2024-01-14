// Realizado por: Félix Hernández Muñoz - Yusta

#include "Entity.hpp"

namespace engine
{
    // Añade un componente a la entidad.
    void Entity::add(const std::string& id, std::shared_ptr<Component> component)
    {
        components[id] = component;
        component->owner = this;
    }

    // Busca y devuelve un componente por su id.
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