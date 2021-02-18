#ifndef CHATPROJECT_MESSAGE_H
#define CHATPROJECT_MESSAGE_H
#include <string>

using namespace std;

class Message {
private:
    string content;
    time_t timestamp;
    string senderUsername;
public:
    Message(string content, time_t timestamp, string username);
    string toString() const ;
    string getSenderUsername() const;
};


#endif //CHATPROJECT_MESSAGE_H
