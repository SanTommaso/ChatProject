#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../classes/User.h"

using namespace std;

TEST(UserTest, UserIDAssignment){
    User firstUser("Mickey");
    User secondUser("Donald");
    User thirdUser("Goofy");

    ASSERT_THAT(1, firstUser.getUserID());
    ASSERT_THAT(2, secondUser.getUserID());
    ASSERT_THAT(3, thirdUser.getUserID());
}

TEST(UserTest, MessageGeneration){
    User writer("Mickey");
    string content = "Hi, my name is Mickey";
    Message mockMessage(content, time(nullptr), "Mickey");
    ASSERT_THAT(mockMessage.toString(), writer.writeMessage(content).toString());

    User anotherWriter("Mockey");
    ASSERT_FALSE(mockMessage.toString().compare(anotherWriter.writeMessage(content).toString()) == 0);
}