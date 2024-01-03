// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "Task.hpp"
#include <list>
#include <map> 
#include <memory>


namespace engine
{
    class System : public Task 
    {
    public:
        virtual std::shared_ptr<Component> create_component(const std::string& id) = 0;
    };
}