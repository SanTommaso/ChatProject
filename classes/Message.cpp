#include "Message.h"
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

Message::Message(string content, time_t timestamp, string username, int senderID){
    this->content = content;
    this->timestamp = timestamp;
    this->username = username;
    this->senderID = senderID;
}

string Message::toString() {
    stringstream returnString;
    returnString << username << " - " << asctime(localtime(&timestamp)) << content << endl;
    return returnString.str();
}

int Message::getSenderID() {
    return senderID;
}


