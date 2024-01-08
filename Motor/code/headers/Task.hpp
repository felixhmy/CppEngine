#pragma once

#include <iostream>
#include <memory>
#include <list>
#include <SDL.h>

#include "System.hpp"
#include "Scene.hpp"
#include "Component.hpp"
#include "internal/Keyboard.hpp"

// OpenGL-toolkit
#include "Model_Obj.hpp"
#include "Render_Node.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "Cube.hpp"
#include "Model.hpp"

using namespace std;

namespace engine 
{
    // Tarea "padre"
    class Task {
    protected:
        Scene* scene;

    public:
        Task(Scene* scene) : scene(scene) {}
        virtual void execute(float t) = 0;
    };

    // Input del usuario
    class InputTask : public Task 
    {
    public:
        InputTask(Scene* scene);
        void execute(float t) override;

    private:
        void KeyPress(SDL_Keycode key);
    };

    // Update del sistema
    class UpdateTask : public Task
    {
    public:
        void execute(float t) override;
    };

    // Render de las partes
    class RenderTask : public Task 
    {
        list<shared_ptr<Model_Component>> components;
        shared_ptr<glt::Render_Node> renderer;

    public:
        RenderTask(Scene* scene);

        shared_ptr<Component> create_component(const std::string& modelPath);

        void execute(float t) override;
    };
}
