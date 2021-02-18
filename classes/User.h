#ifndef CHATPROJECT_USER_H
#define CHATPROJECT_USER_H
#include <string>
#include "Message.h"

using namespace std;

class User {
private:
    int userID;
    string username;

public:
    User(string username);
    int getUserID() const;
    Message writeMessage(string content);
};


#endif //CHATPROJECT_USER_H
