// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once


#include "rapidxml/rapidxml.hpp"
#include <glm/glm.hpp>

#include "System.hpp"

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

    class Component
    {
    public:
        Entity* owner;
        virtual ~Component() = default;
    };

    struct Transform_Component : public Component
    {
        Transform_Component* parent;
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        glm::mat4 get_matrix() const;
    };

    struct Model_Component : public Component
    {
        shared_ptr<glt::Model> model;
    };


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