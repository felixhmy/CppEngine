// Realizado por: Félix Hernández Muñoz - Yusta

#include "Controller.hpp"

#include <glm/gtc/matrix_transform.hpp>


namespace engine
{
    // Constructor de Control_System: inicializa el sistema y almacena las fábricas de controladores.
    Control_System::Control_System(const map<string, Controller_Factory>& given_control_factories, Scene * scene): System (scene), controller_factories(given_control_factories)
    {
        // Pendiente de implementar
    }

    // Crea un componente de control a partir de un XML.
    shared_ptr<Component> Control_System::create_component(Entity& entity, const std::string& component_id, const xml_node<>* data)
    {
        
        auto component = make_shared<Control_Component>();
        
        string factory_id = data->first_attribute("controller")->value();
        auto factory = controller_factories[factory_id];
        //component->controller = factory();
        components.push_back(component);
        
        return component;
    }

    // Ejecuta la lógica de actualización para cada componente de control.
    void Control_System::execute(float t)
    {
        for (auto& component : components)
        {
            component->controller->update(*component->owner, t);
        }
    }
}