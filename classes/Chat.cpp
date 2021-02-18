#include <iostream>
#include "Chat.h"

Chat::Chat(const User &user1, const User &user2)
:user1(user1), user2(user2)
{}

void Chat::addMessage(Message message)  {
    if(message.getSenderUsername().compare(user1.getUsername()) == 0 || message.getSenderUsername().compare(user2.getUsername()) == 0){
        messages.push_back(message);
    } else {
        std::cout << "Only chat participants can write a message" << endl;
    }
}

vector<Message>::iterator Chat::getMessages() {
    return messages.begin();
}

bool Chat::checkParticipants(string usr1, string usr2) {
    if(user1.getUsername().compare(usr1) == 0)
        if(user2.getUsername().compare(usr2) == 0){
            return true;
        }
    if(user2.getUsername().compare(usr1) == 0)
        if(user1.getUsername().compare(usr2) == 0){
            return true;
        }

    return false;
}