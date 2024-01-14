// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include <list>
#include "Task.hpp"

namespace engine
{
	//Actúa como un gestor de tareas en el motor.
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