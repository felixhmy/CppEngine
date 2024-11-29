// Autor: felixhmy

#pragma once

#include "Task.hpp"

#include <string>
#include <map>
#include <list>
#include <variant>


namespace engine
{
    // Estructura del mensaje.
    struct Message
    {
        std::string id;
        using Parameter = std::variant<int, std::string>;
        std::map<std::string, Parameter> parameters;
    };

    // Se encarga de recibir los mensajes.
    class Message_Listener
    {
    public:
        // Maneja los mensajes recibidos.
        virtual void handle(const Message& message) = 0;
    };

    // Se encarga de administrar y enviar los mensajes.
    class Message_Dispatcher : public Task
    {
    private:
        std::list<Message> messages; // Lista de mensajes.
        std::map<std::string, std::list<Message_Listener*>> message_listeners; // Lista de listeners.

    public:
        void add(Message_Listener& listener, const std::string& message_id);
        void send(const Message& message);
        void execute(float t) override;
    };
}
