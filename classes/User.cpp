#include "User.h"
#include <string>
#include <ctime>

using namespace std;

static int progressiveID = 1;

User::User(string username){
    this->username = username;
    this->userID = progressiveID;
    progressiveID++;
}

int User::getUserID() const {
    return userID;
}

Message User::writeMessage(string content) {
    Message message(content, time(nullptr), username, userID);
    return message;
}

