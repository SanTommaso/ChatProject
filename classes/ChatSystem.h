#ifndef CHATPROJECT_CHATSYSTEM_H
#define CHATPROJECT_CHATSYSTEM_H


#include "User.h"
#include "Chat.h"
#include <vector>

class ChatSystem {
private:
    vector<User> users = {};
    vector<Chat> chats = {};
    Chat createChat(const User& user1, const User& user2);
public:
    ChatSystem();
    bool addUser(string username);
    bool sendMessage(string senderUsername, string receiverUsername, string content);
    vector<Chat> getChats();

};


#endif //CHATPROJECT_CHATSYSTEM_H
