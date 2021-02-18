#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../classes/ChatSystem.h"

TEST(ChatSystemTest, UserInsertion){
    ChatSystem chatSys;
    ASSERT_TRUE(chatSys.addUser("Mickey"));
    ASSERT_TRUE(chatSys.addUser("Goofy"));
    ASSERT_FALSE(chatSys.addUser("Mickey"));
}