// Autor: felixhmy

#pragma once

#include <map>
#include <string>
#include <memory>

#include "Component.hpp"

namespace engine
{
    // Representa una entidad en el juego, que puede tener varios componentes.
    class Entity 
    {
        // Mapa de componentes asociados a esta entidad.
        std::map<std::string, std::shared_ptr<Component>> components;

        Transform_Component transform;


    public:

        // Añade un componente a la entidad.
        void add(const std::string& id, std::shared_ptr<Component> component);

        // Devuelve al componente de transformación de la entidad.
        auto& get_transform()
        {
            return transform;
        }

        // Obtiene un componente por su id.
        Component* get_component_by_id(const std::string& id);
    };

}
