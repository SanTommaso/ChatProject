#include <iostream>
#include <sstream>
#include "ChatSystem.h"

ChatSystem::ChatSystem() { }

bool ChatSystem::addUser(string username) {
    bool found = false;
    vector<User>::iterator it = users.begin();

    for(it; it != users.end(); ++it){
        found = it->getUsername().compare(username) == 0 ? true : false;
        if(found) break;
    }

    if(!found){
        users.push_back(User(username));
        return true;
    }

    return false;
}

Chat ChatSystem::createChat(const User &user1, const User &user2) {
    return Chat(user1,user2);
}

vector<Chat> ChatSystem::getChats(){
    return chats;
}

bool ChatSystem::sendMessage(string senderUsername, string receiverUsername, string content) {
    vector<User>::iterator sender = users.begin();
    vector<User>::iterator receiver = users.begin();
    bool senderFound = false, receiverFound = false;
    for(int i = 0; i < users.size(); i++){
        if(!senderFound) {
            if(sender->getUsername().compare(senderUsername) == 0){
                senderFound=true;
            } else {
                sender++;
            }
        }
        if(!receiverFound){
            if(receiver->getUsername().compare(receiverUsername) == 0){
                receiverFound=true;
            }
            else{
                receiver++;
            }
        }
        if(senderFound&&receiverFound) break;
    }
    if(senderFound&&receiverFound){
        cout << "trovati\n";
        bool found = false;
        if(!chats.empty()){
            for(Chat chat : chats){
                found = chat.checkParticipants(senderUsername, receiverUsername);
                cout << "check = " + found;
                if(found){
                    cout << "\naggiungo il messaggio a chat esistente\n";
                    chat.addMessage(sender->writeMessage(content));
                    return true;
                }
            }
        }
        chats.emplace_back(createChat(*sender, *receiver));
        chats.front().addMessage(sender->writeMessage(content));
        return true;
    }
    return false;
}

string ChatSystem::printChats() {
    stringstream ss;
    for(Chat chat : chats){
        ss << chat.Export() + "\n-------------------\n";
    }
    return ss.str();
}