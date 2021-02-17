#ifndef CHATPROJECT_MESSAGE_H
#define CHATPROJECT_MESSAGE_H
#include <string>
using namespace std;

class Message {
private:
    string content;
    time_t timestamp;
    string username;

public:
    Message(string content, time_t timestamp, string username);
    string toString();
};


#endif //CHATPROJECT_MESSAGE_H
