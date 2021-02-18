#include "User.h"
#include <string>
#include <ctime>

using namespace std;

User::User(string username){
    this->username = username;
}

Message User::writeMessage(string content) const {
    Message message(content, time(nullptr), username);
    return message;
}

string User::getUsername() const {
    return username;
}

