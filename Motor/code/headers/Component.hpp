// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "Entity.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Model.hpp"
#include "Camera.hpp"
#include "Light.hpp"

using namespace std;

namespace engine
{
    struct Component 
	{
        Entity* owner;
		virtual ~Component() = default;
    };

	struct Transform_Component : public Component
	{
		glm::vec3 position; // Posicion del componente
		glm::vec3 rotation; // Angulo de rotación
		glm::vec3 scale;	// Escala en base al objeto

		glm::mat4 get_matrix() const
		{
			glm::mat4 matrix(1);
			matrix = glm::translate(matrix, position);
			matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1, 0, 0)); // Rotación en X
			matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(0, 1, 0)); // Rotación en Y
			matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(0, 0, 1)); // Rotación en Z
			matrix = glm::scale(matrix, scale); // Escala
			return matrix;
		}
	};

	struct Model_Component : public Component
	{
		shared_ptr < glt::Model > model;
		
	};

	struct Camera_Component : public Component
	{
		shared_ptr < glt::Camera > camera;
	};

	struct Light_Component :public Component
	{
		shared_ptr < glt::Light > light;
	};
}