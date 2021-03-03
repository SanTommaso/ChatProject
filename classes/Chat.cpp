#include <iostream>
#include <sstream>
#include "Chat.h"

Chat::Chat(const User& first, const User& second)
:user1(first),user2(second)
{}

bool Chat::addMessage(Message message)  {
    if(message.getSenderUsername().compare(user1.getUsername()) == 0 || message.getSenderUsername().compare(user2.getUsername()) == 0){
        messages.emplace_back(message);
        return true;
    } else {
        return false;
    }
}

int Chat::messagesAmount() {
    return messages.size();
}

bool Chat::readChat(string username) {
    if(username._Equal(user1.getUsername()) || username._Equal(user2.getUsername())){
        for(Message& msg : messages){
            if(msg.getSenderUsername()._Equal(username))
                msg.readMessage();
        }
        return true;
    } else {
        return false;
    }
}

Message Chat::getMessage(int index) {
    if(messages.size() == 0)
        throw "There are no messages in the chat, no message can be retrieved";

    if(index < 0 || index > messages.size()-1)
        throw std::invalid_argument("Invalid argument : " + index);

    return messages.at(index);
}

int Chat::unreadMessagesAmount() {
    int amount = 0;
    for(Message msg : messages){
        if(!msg.readStatus())
            amount++;
    }
    return amount;
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

string Chat::toString(){
    stringstream wholeChat;
    wholeChat << "Chat between " + user1.getUsername() + " and " + user2.getUsername() + ":\n";
    for(Message msg : messages){
        wholeChat << msg.toString() << endl;
    }

    return wholeChat.str();
}


