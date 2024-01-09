// Realizado por: Félix Hernández Muñoz - Yusta

#include "Scene.hpp"

using namespace engine;
using namespace std;

int main() 
{
	Window window("Motores Felix Hernandez Muñoz-Yusta", 1024, 768, false);
	Scene scene(window, "ruta-al-archivo-xml-de-la-escena");

	scene.run();

	return 0;
}