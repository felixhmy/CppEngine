// Realizado por: Félix Hernández Muñoz - Yusta

#include "Scene.hpp"

namespace engine
{
	Scene::Scene(Window& window, const std::string& scene_file_path) : input_task(this), render_system (this), window (&window)
	{
		kernel.add(input_task);
		kernel.add(render_system);

		load_scene();
	}

	Window& Scene::get_window()
	{
		return *window;
	}

	void Scene::run()
	{
		kernel.run();
	}

	void Scene::stop()
	{
		kernel.stop();
	}


	void Scene::load_scene()
	{
		// cargar entity
		auto entity = std::make_shared<Entity>();

		entities[render_system.entity_id] = entity;
		

		//transform
		entity->get_transform();

		//component
		auto component = render_system.create_component(*entity, "model");
		entity->add("model", component);
	}

}




/*
	void Scene::load_scene_xml (const string& scene_file_path)
	{
		std::ifstream reader(scene_file_path, ifstream::binary);
		reader.seekg(0, ifstream::end);
		size_t size = reader.tellg();
		reader.seekg(0, ifstream::beg);
		string xml_data;
		xml_data.resize(size);
		reader.read(&xml_data.front(), size);

		xml_document <> xml_dom;
		xml_dom.parse<0>(const_cast<char*>(xml_data.c_str()));
		xml_node<>* scene_node = xml_dom.first_node("scene");
		if (string(scene_node->name()) == "scene")
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

	void Scene::parse_entity_node(xml_node<>* entity_node, const string& id, Entity& entity)
	{
		for (auto child = entity_node->first_node(); child != nullptr; child = child->next_sibling())
		{
			string name = child->name();

			if (name == "transform")
			{
				// CREAR PARSE_TRANSFORM PARA OBTENER A LA VEZ LA X,Y,Z
				//entity->set_transform(parse_transform(child));
				parse_transform(child, entity);
			}
			else if (name == "model")
			{
				// auto component = render_system.create_component(entity, id, child);
				auto component = render_system.create_component(entity, "model");

				entity.add("model", component);
			}
			// Faltan crear el resto de componentes (camera, light, etc)
		}
	}

	void Scene::parse_transform(xml_node<>* transform_node, Entity& entity)
	{
		glm::vec3 position(0.0f), rotation(0.0f), scale(1.0f);

		for (auto child = transform_node->first_node(); child; child = child->next_sibling())
		{
			string name = child->name();
			float value = float (atof(child->value()));

			if (name == "x") position.x = value;
			else if (name == "y") position.y = value;
			else if (name == "z") position.z = value;
			
		}
		entity.get_transform().position = position;
	}
*/