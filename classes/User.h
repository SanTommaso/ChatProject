#ifndef CHATPROJECT_USER_H
#define CHATPROJECT_USER_H
#include <string>
#include "Message.h"

using namespace std;

class User {
private:
    string username;
public:
    User(string username);
    Message writeMessage(string content) const;
    string getUsername() const;
};


#endif //CHATPROJECT_USER_H
