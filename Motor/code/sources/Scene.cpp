// Realizado por: Félix Hernández Muñoz - Yusta

#include "Scene.hpp"



namespace engine
{
    Scene::Scene(Window& window, const std::string& scene_file_path) // : RenderTask(this) 
    {
        kernel.add(input_task);
        kernel.add(render_task);
        kernel.add(update_task);

        load_scene(scene_file_path);
    }

    Window& Scene::get_window()
    {
        return *window;
    }

    Window& Scene::swap_buffers()
    {

    }

    void Scene::run() 
    {
        kernel.run();
    }



    void Scene::load_scene(const string& scene_file_path)
    {
        std::ifstream reader(scene_file_path, ifstream::binary);
        reader.seekg(0, ifstream::end);
        size_t size = reader.tellg();
        reader.seekg(0, ifstream::beg);
        string xml_data(size);
        reader.read(&xml_data.front(), size);

        xml_document <> xml_dom;
        xml_dom.parse<0>(xml_data.c_str());
        xml_node<> * scene_node = xml_dom.first_node("scene");
        if (string(scene_node->name() == "scene"))
        {
            parse_scene_node(scene_node);
        }
    }

    void Scene::parse_scene_node(xml_node<>* scene_node)
    {
        for (auto child = scene_node->first_node(); child != nullptr; child = child->next_sibling())
        {
            if (string(child->name()) == "entity")
            {
                auto entity = std::make_shared<Entity>();
                auto id_attribute = child->first_attribute("id");
                string id = id_attribute->name();

                if (id_attribute)
                {
                    entities[id] = entity;
                }

                parse_entity_node(child, id, *entity);
			}
        }
    }

    void Scene::parse_entity_node(xml_node<>* entity_node,const string & id, Entity & entity)
    {
        for (auto child = entity_node->first_node(); child != nullptr; child = child->next_sibling())
        {
            string name = child->name();

            if (name == "transform")
            {
                // CREAR PARSE_TRANSFORM PARA OBTENER A LA VEZ LA X,Y,Z
                entity->set_transform (parse_transform(child));
            }
            else if (name == "model")
            {
               // auto component = render_task.create_component(entity, id, child);
                auto component = render_task.create_component(entity, "model");

                entity.add ("model", component);
            }
            // Faltan crear el resto de componentes (camera, light, etc)
        }
}




