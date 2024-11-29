#include "Component.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace engine
{
    // Esta función crea una matriz de 4x4 a partir de los componentes de posición, rotación y escala.
    glm::mat4 Transform_Component::get_matrix() const
    {
        glm::mat4 matrix(1);
        matrix = glm::translate(matrix, position);
        matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1, 0, 0)); // X
        matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(0, 1, 0)); // Y
        matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(0, 0, 1)); // Z
        matrix = glm::scale(matrix, scale);
        
        if (parent)
        {
            return parent->get_matrix() * matrix;
        }
        else
        {
            return matrix;
        }

    }
}