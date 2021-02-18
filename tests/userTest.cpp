#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../classes/User.h"

using namespace std;

TEST(UserTest, MessageGeneration){
    User writer("Mickey");
    string content = "Hi, my name is Mickey";
    Message message(content, time(nullptr), "Mickey");
    ASSERT_THAT(message.toString(), writer.writeMessage(content).toString());

    User anotherWriter("Mockey");
    ASSERT_FALSE(message.toString().compare(anotherWriter.writeMessage(content).toString()) == 0);
}