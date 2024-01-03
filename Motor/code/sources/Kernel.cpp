// Realizado por: Félix Hernández Muñoz - Yusta

#include "Kernel.hpp"
#include "Timer.hpp"

namespace engine
{


    void Kernel::add(Task& task) 
	{
        tasks.push_back(&task);
    }

    void Kernel::run() 
	{
		exit = false;

		float time = 1.f / 60.f;

		do
		{
			Timer timer;

			for (auto task : tasks) task->execute(time);

			time = timer.get_elapsed_seconds();
		} while (!exit);
    }

    void Kernel::stop() 
	{
        exit = true;
    }
}