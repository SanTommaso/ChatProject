#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../classes/ChatSystem.h"

TEST(ChatSystemTest, UserInsertion){
    ChatSystem chatSys;
    ASSERT_TRUE(chatSys.addUser("Mickey"));
    ASSERT_TRUE(chatSys.addUser("Goofy"));
    ASSERT_FALSE(chatSys.addUser("Mickey"));
}

TEST(ChatSystemTest, SendMessage){
    ChatSystem chatSys;
    chatSys.addUser("Mickey");
    chatSys.addUser("Goofy");
    chatSys.addUser("Donald");
    ASSERT_TRUE(chatSys.sendMessage("Mickey","Goofy","Hi Goofy! How are you?"));
    ASSERT_TRUE(chatSys.getChats().front().checkParticipants("Mickey","Goofy"));
    ASSERT_TRUE(chatSys.sendMessage("Goofy","Mickey","Hi Mickey! it's nice to see you"));
    ASSERT_EQ(chatSys.getChats().size(),1);
    ASSERT_FALSE(chatSys.sendMessage("Pete","Mickey","I'm not in your chatSystem, so I shouldn't be able to send this message"));
    ASSERT_TRUE(chatSys.sendMessage("Donald","Goofy","I'm late!"));
    ASSERT_EQ(chatSys.getChats().size(),2);
}