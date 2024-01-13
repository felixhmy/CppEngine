// Realizado por: Félix Hernández Muñoz - Yusta

#pragma once

#include <string>
#include <map>
#include <list>
#include <variant>

#include "Task.hpp"


namespace engine
{
    struct Message
    {
        std::string id;
        using Parameter = std::variant<int, std::string>;
        std::map<std::string, Parameter> parameters;
    };

    // Interfaz de escuchador de mensajes
    class Message_Listener
    {
    public:
        virtual void handle(const Message& message) = 0;
    };

    // Clase para despachar mensajes
    class Message_Dispatcher : public Task
    {
    private:
        std::list<Message> messages;
        std::map<std::string, std::list<Message_Listener*>> message_listeners;

    public:
        void add(Message_Listener& listener, const std::string& message_id);
        void send(const Message& message);
        void execute() override;
    };
}