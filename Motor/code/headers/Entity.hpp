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
        std::map<std::string, std::shared_ptr<Component>> components; // Malla de Componentes 
        Transform_Component transform;

    public:
        void add(const std::string& id, std::shared_ptr<Component> component); //Añadir a la malla
        auto& get_transform();
    };

}