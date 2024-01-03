// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include <list>
#include "Task.hpp"

namespace engine
{
	class Kernel 
	{

		std::list<Task*> tasks; // Lista de tareas
		bool exit;

	public:
		void add(Task& task); //Añade tareas a la lista
		void run();
		void stop();
	};
}





