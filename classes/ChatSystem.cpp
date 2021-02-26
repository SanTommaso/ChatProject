#include <iostream>
#include <sstream>
#include "ChatSystem.h"

ChatSystem::ChatSystem() { }

bool ChatSystem::addUser(string username) {
    User tempUser(username);
    auto insertionResult = users.insert(tempUser);
    return insertionResult.second;
}

Chat ChatSystem::createChat(const User &user1, const User &user2) {
    return Chat(user1,user2);
}

int ChatSystem::chatsAmount(){
    return chats.size();
}

bool ChatSystem::sendMessage(string senderUsername, string receiverUsername, string content) {
    User sender(senderUsername), receiver(receiverUsername);
    bool senderFound = users.find(sender) != users.end();
    bool receiverFound = users.find(receiver) != users.end();
    if(senderFound&&receiverFound){
        bool found = false;
        if(!chats.empty()){
            for(Chat &chat : chats){
                found = chat.checkParticipants(senderUsername, receiverUsername);
                if(found){
                    chat.addMessage(sender.writeMessage(content));
                    return true;
                }
            }
        }
        Chat toInsert = createChat(sender, receiver);
        toInsert.addMessage(sender.writeMessage(content));
        cout << "Aggiungo nuova chat\n";
        chats.push_back(toInsert);
        return true;
    }
    return false;
}

string ChatSystem::toString() {
    stringstream ss;
    for(Chat chat : chats){
        ss << chat.toString() + "\n-------------------\n";
    }
    return ss.str();
}

void ChatSystem::readAllChats(string username) {
    for(Chat chat : chats)
        chat.readChat("username");
}