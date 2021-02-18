#include <gtest/gtest.h>
#include <string>
#include "../classes/Message.h"
#include "../classes/User.h"

using namespace std;

TEST(MessageTest, ToString){
    string content = "This is a message";
    time_t timestamp = time(nullptr);
    string  username = "Mickey";
    User user(username);
    Message message(content, timestamp, username, user.getUserID());

    stringstream expectedToStringOutput;
    expectedToStringOutput << username << " - "
    << asctime(localtime(&timestamp)) << content << endl;

    ASSERT_EQ(expectedToStringOutput.str(), message.toString());
}
