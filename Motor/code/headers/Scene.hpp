// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "internal/Window.hpp"
#include "Component.hpp"
#include "Entity.hpp"
#include "Kernel.hpp"
#include "System.hpp"
#include "Task.hpp"


#include <map>
#include <memory>
#include <string>
#include <fstream>

#include "rapidxml/rapidxml.hpp"
using namespace rapidxml;

namespace engine
{
    class Scene 
    {
        Window* window;

        std::map<std::string, std::shared_ptr<Entity>> entities;

        Kernel kernel;

        InputTask input_task;
        RenderSystem render_system;
        

    public:
        Scene(Window & window, const std::string & scene_file_path);
        Window& get_window();
        void run();
        void stop();

    private:
        void load_scene();
        
        // void load_scene_xml(const string& scene_file_path);
        // void parse_scene_node(xml_node<>* scene_node);
        // void parse_entity_node(xml_node<>* entity_node, const string& id, Entity & entity);
        // void parse_transform(xml_node<>* transform_node, Entity& entity);
    };
}





