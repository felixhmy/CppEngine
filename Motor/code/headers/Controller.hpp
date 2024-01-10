// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once


#include "rapidxml/rapidxml.hpp"
#include <glm/glm.hpp>

#include "System.hpp"
#include "Component.hpp"

#include <memory>
#include <list>
#include <map>
#include <string>

using namespace std;
using namespace rapidxml;

namespace glt { class Model; }

namespace engine
{
    class Entity;
    class Scene;

    class Controller
    {
    public:
        virtual void update(Entity& entity, float t) = 0;
    };

    typedef shared_ptr<Controller>(*Controller_Factory)();

    struct Control_Component : public Component
    {
        Controller* controller;
    };

    
    class Control_System : public System
    {
        list<shared_ptr<Control_Component>> components;
        map<string, Controller_Factory> controller_factories;

    public:
        Control_System(const map<string, Controller_Factory>& given_control_factories, Scene *scene);
        shared_ptr<Component> create_component(Entity& entity, const std::string& component_id, const xml_node<>* data);
        void execute(float t) override;
    };
}