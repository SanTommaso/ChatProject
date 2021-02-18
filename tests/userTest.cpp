#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../classes/User.h"

using namespace std;

TEST(UserTest, UserIDAssignment){
    User firstUser("Mickey");
    User secondUser("Donald");
    User thirdUser("Goofy");

    ASSERT_THAT(2, firstUser.getUserID());
    ASSERT_THAT(3, secondUser.getUserID());
    ASSERT_THAT(4, thirdUser.getUserID());
}

TEST(UserTest, MessageGeneration){
    User writer("Mickey");
    string content = "Hi, my name is Mickey";
    Message message(content, time(nullptr), "Mickey", writer.getUserID());
    ASSERT_THAT(message.toString(), writer.writeMessage(content).toString());

    User anotherWriter("Mockey");
    ASSERT_FALSE(message.toString().compare(anotherWriter.writeMessage(content).toString()) == 0);
}