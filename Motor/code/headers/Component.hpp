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
}