#include "Scene.hpp"

using namespace engine;
using namespace std;

int main() 
{
	Window window("Motores Felix Hernandez Muñoz-Yusta", 1024, 768, false);

	Scene scene(window, "..\..\Motor\binaries\scene-data.xml");
	scene.run();

	return 0;
}