#ifndef CHATPROJECT_USER_H
#define CHATPROJECT_USER_H
#include <string>

using namespace std;

class User {
private:
    int userID;
    string username;

public:
    User(string username);
    int getUserID();
};


#endif //CHATPROJECT_USER_H
