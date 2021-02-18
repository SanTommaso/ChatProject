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

Chat ChatSystem::addChat(const User &user1, const User &user2) {
    return Chat(user1,user2);
}

