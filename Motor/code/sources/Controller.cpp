// Realizado por: Félix Hernández Muñoz - Yusta

#include "Controller.hpp"

#include <glm/gtc/matrix_transform.hpp>


namespace engine
{
    Control_System::Control_System(const map<string, Controller_Factory>& given_control_factories, Scene * scene): System (scene), controller_factories(given_control_factories)
    {
        /// MAS ADELANTE
    }

    shared_ptr<Component> Control_System::create_component(Entity& entity, const std::string& component_id, const xml_node<>* data)
    {
        
        auto component = make_shared<Control_Component>();
        /*
        string factory_id = data->first_attribute("controller")->value();
        auto factory = controller_factories[factory_id];
        component->controller = factory();
        components.push_back(component);
        */
        
        return component;
    }

    void Control_System::execute(float t)
    {
      /*
        for (auto& component : components)
        {
            component->controller->update(*component->owner, t);
        }
      */
    }
}
