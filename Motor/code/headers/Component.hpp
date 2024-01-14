// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once
 
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

    // Representa un componente en una entidad del juego, cada entidad puede tener varios componentes.
    class Component
    {
    public:
        Entity* owner; // Puntero al propietario de este componente.
        virtual ~Component() = default;
    };

    // Tipo específico de Component que almacena información de transformación (posición, rotación y escala).
    struct Transform_Component : public Component
    {
        Transform_Component* parent;
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        glm::mat4 get_matrix() const;  // Función para calcular la matriz de transformación.
    };

    // Tipo específico de Component que almacena un modelo 3D mediante openGL-toolkit.
    struct Model_Component : public Component
    {
        shared_ptr<glt::Model> model;
    };
}