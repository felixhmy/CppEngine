// Autor: felixhmy 
// Todos los derechos reservados © 2025 

#pragma once

#include <list>
#include "Task.hpp"

namespace engine
{
	//Actúa como gestor de tareas en el motor.
	class Kernel 
	{
		std::list<Task*> tasks;
		bool exit;

	public:
		void add(Task& task);
		void run();
		void stop();
	};
}
