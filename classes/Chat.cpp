//
// Created by Sendo on 2/18/2021.
//

#include <iostream>
#include "Chat.h"

Chat::Chat(const User &user1, const User &user2)
:user1(user1), user2(user2)
{}

void Chat::addMessage(Message message)  {
    if(message.getSenderID() == user1.getUserID() || message.getSenderID() == user2.getUserID()){
        messages.push_back(message);
    } else {
        std::cout << "Only chat participants can write a message" << endl;
    }
}

vector<Message>::iterator Chat::getMessages() {
    return messages.begin();
}