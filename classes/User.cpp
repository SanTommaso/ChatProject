//
// Created by Sendo on 2/17/2021.
//

#include "User.h"
#include <string>
using namespace std;

static int progressiveID = 1;

User::User(string username){
    this->username = username;
    this->userID = progressiveID++;
}

int User::getUserID() {
    return userID;
}

