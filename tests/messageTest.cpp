#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../classes/Message.h"

using namespace std;

TEST(MessageTest, ToString){
    string mockContent = "This is a message";
    time_t mockTime = time(nullptr);
    string  mockUsername = "Mickey";
    Message message(mockContent, mockTime, mockUsername);

    stringstream expectedToStringOutput;
    expectedToStringOutput << mockUsername << " - "
    << asctime(localtime(&mockTime)) << mockContent << endl;
    cout << expectedToStringOutput.str();
    ASSERT_EQ(expectedToStringOutput.str(), message.toString());
}
