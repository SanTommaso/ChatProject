#ifndef CHATPROJECT_CHATSYSTEM_H
#define CHATPROJECT_CHATSYSTEM_H


#include "User.h"
#include "Chat.h"
#include <unordered_set>

class ChatSystem {
private:
    unordered_set<User> users = {};
    vector<Chat> chats = {};
    Chat createChat(const User& user1, const User& user2);
public:
    ChatSystem();
    bool addUser(string username);
    bool sendMessage(string senderUsername, string receiverUsername, string content);
    int chatsAmount();
    void readAllChats(string username);
    string toString();
};


#endif //CHATPROJECT_CHATSYSTEM_H
