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

    // Define una interfaz para controladores que cambian las entidades del juego.
    class Controller
    {
    public:
        virtual void update(Entity& entity, float t) = 0;
    };

    // Función para fábricas de controladores.
    typedef shared_ptr<Controller>(*Controller_Factory)();

    // Almacena un puntero de un controlador, se añade a una entidad para controlarla.
    struct Control_Component : public Component
    {
        Controller* controller;
    };

    // Es un sistema que se encarga la creación y ejecución de estos componentes.
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