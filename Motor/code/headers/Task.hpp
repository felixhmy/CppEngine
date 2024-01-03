#pragma once

#include <iostream>
#include <memory>
#include <list>

#include "System.hpp"
#include "Scene.hpp"
#include "Component.hpp"

#include "Model_Obj.hpp"
#include "Render_Node.hpp"
#include "Light.hpp"
#include "Camera.hpp"

using namespace std;

namespace engine 
{

    class Task 
    {
    protected:
        Scene* scene;

    public:
        Task(Scene* scene) : scene(scene) {}
        virtual void execute(float t) = 0;
    };

    class InputTask : public Task 
    {
    public:
        InputTask(Scene* scene) : Task(scene) {}
        void execute(float t) override;
    };

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
