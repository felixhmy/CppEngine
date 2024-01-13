// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include "Task.hpp"

#include <string>
#include <map>
#include <list>
#include <variant>


namespace engine
{
    struct Message
    {
        std::string id;
        using Parameter = std::variant<int, std::string>;
        std::map<std::string, Parameter> parameters;
    };

    class Message_Listener
    {
    public:
        virtual void handle(const Message& message) = 0;
    };

    class Message_Dispatcher : public Task
    {
    private:
        std::list<Message> messages;
        std::map<std::string, std::list<Message_Listener*>> message_listeners;

    public:
        void add(Message_Listener& listener, const std::string& message_id);
        void send(const Message& message);
        void execute(float t) override;
    };
}