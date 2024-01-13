// Realizado por: Félix Hernández Muñoz - Yusta

#include "Message.hpp"

namespace engine
{
    void Message_Dispatcher::add(Message_Listener& listener, const std::string& message_id)
    {
        message_listeners[message_id].push_back(&listener);
    }

    void Message_Dispatcher::send(const Message& message)
    {
        messages.push_back(message);
    }

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