#ifndef CHATPROJECT_CHAT_H
#define CHATPROJECT_CHAT_H

#include <vector>
#include "Message.h"
#include "User.h"

class Chat {
private:
    User user1;
    User user2;
    vector<Message> messages = {};
public:

    Chat(User first,User second);
    bool addMessage(Message message);
    Message getMessage(int index);
    bool checkParticipants(string usr1, string usr2);
    int messagesAmount();
    bool readChat(string username);
    int unreadMessagesAmount();
    string toString();
};


#endif //CHATPROJECT_CHAT_H
