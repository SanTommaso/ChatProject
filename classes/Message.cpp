#include "Message.h"
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

Message::Message(string content, time_t timestamp, string senderUsername){
    this->content = content;
    this->timestamp = timestamp;
    this->senderUsername = senderUsername;
    this->read = false;
}

string Message::toString() const {
    stringstream returnString;
    returnString << senderUsername << " - " << asctime(localtime(&timestamp)) << content << endl;
    return returnString.str();
}

string Message::getSenderUsername() const {
    return senderUsername;
}

void Message::readMessage() {
    this->read = true;
}

bool Message::readStatus() const {
    return read;
}

