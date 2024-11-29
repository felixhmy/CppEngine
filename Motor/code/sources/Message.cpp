#include "Message.hpp"

namespace engine
{
    // Añade un listener para un tipo especifico de mensaje.
    void Message_Dispatcher::add(Message_Listener& listener, const std::string& message_id)
    {
        message_listeners[message_id].push_back(&listener);
    }

    // Añade un mensaje a la lista de mensajes por enviar.
    void Message_Dispatcher::send(const Message& message)
    {
        messages.push_back(message);
    }

    // Envía todos los mensajes pendientes a sus listerners.
    void Message_Dispatcher::execute(float t)
    {
        for (auto& message : messages)
        {
            auto& listeners = message_listeners[message.id];
            for (auto& listener : listeners)
            {
                listener->handle(message);
            }
        }
        messages.clear();
    }
}