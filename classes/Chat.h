#ifndef CHATPROJECT_CHAT_H
#define CHATPROJECT_CHAT_H

#include <vector>
#include "Message.h"
#include "User.h"

class Chat {
private:
    const User& user1;
    const User& user2;
    vector<Message> messages = {};
public:
    Chat(const User& user1,const User& user2);
    void addMessage(Message message);
    vector<Message>::iterator getMessages();
};


#endif //CHATPROJECT_CHAT_H
