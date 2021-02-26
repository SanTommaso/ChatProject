#ifndef CHATPROJECT_USER_H
#define CHATPROJECT_USER_H
#include <string>
#include "Message.h"
#include <utility>
using namespace std;

class User {
private:
    string username;
public:
    friend bool operator== (const User& left, const User& right){
        return left.username == right.username;
    }
    User(string username);
    Message writeMessage(string content) const;
    string getUsername() const;
};

namespace std
{
    template<> struct hash<User>
    {
        std::size_t operator()(User const& user) const noexcept
        {
            return std::hash<std::string>{}(user.getUsername());
        }
    };
}

#endif //CHATPROJECT_USER_H
