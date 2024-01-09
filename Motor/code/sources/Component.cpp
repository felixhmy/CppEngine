// Realizado por: Félix Hernández Muñoz - Yusta

#include "Component.hpp"

namespace engine
{
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

    Control_System::Control_System(const map<string, Controller_Factory>& given_control_factories)
        : controller_factories(given_control_factories)
    {

    }

    shared_ptr<Component> Control_System::create_component(Entity& entity, const std::string& component_id, const xml_node<>* data)
    {
        auto component = make_shared<Control_Component>();
        string factory_id = data->first_attribute("controller")->value();
        auto factory = controller_factories[factory_id];
        component->controller = factory();
        components.push_back(component);
        return component;
    }

    void Control_System::execute(float t)
    {
        for (auto& component : components)
        {
            component->controller->update(component->owner, t);
        }
    }
}
