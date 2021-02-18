#ifndef CHATPROJECT_MESSAGE_H
#define CHATPROJECT_MESSAGE_H
#include <string>

using namespace std;

class Message {
private:
    string content;
    time_t timestamp;
    string username;
    int senderID;
public:
    Message(string content, time_t timestamp, string username, int senderID);
    string toString();
    int getSenderID();
};


#endif //CHATPROJECT_MESSAGE_H
