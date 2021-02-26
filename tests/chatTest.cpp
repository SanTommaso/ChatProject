#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../classes/User.h"
#include "../classes/Chat.h"

using namespace std;

TEST(ChatTest, GetMessage){
    User first("Mickey");
    User second("Donald");
    Message msg = first.writeMessage("This is a message");
    Chat chat(first,second);

    EXPECT_ANY_THROW(chat.getMessage(0));
    chat.addMessage(msg);
    EXPECT_ANY_THROW(chat.getMessage(1));
    ASSERT_EQ(msg.toString(),chat.getMessage(0).toString());
}

TEST(ChatTest, MessageInsertion){
    User first("Mickey");
    User second("Donald");
    Message msgFromFirst = first.writeMessage("Hi! I'm Mickey!!");
    Message msgFromSecond = second.writeMessage("Hi Mickey! my name is Donald.");

    Chat chat(first,second);
    chat.addMessage(msgFromFirst);
    chat.addMessage(msgFromSecond);

    Message expectedFirst = chat.getMessage(0);
    Message expectedSecond = chat.getMessage(1);
    ASSERT_THAT(msgFromFirst.toString(),expectedFirst.toString());
    ASSERT_THAT(msgFromSecond.toString(),expectedSecond.toString());
}

TEST(ChatTest, UnreadMessagesAmount){
    User first("Mickey");
    User second("Donald");
    Message msgFromFirst = first.writeMessage("Hi! I'm Mickey!!");
    Chat chat(first,second);
    ASSERT_EQ(chat.messagesAmount(),0);
    ASSERT_EQ(chat.unreadMessagesAmount(), 0);
    msgFromFirst.readMessage();
    chat.addMessage(msgFromFirst);
    ASSERT_EQ(chat.messagesAmount(),1);
    ASSERT_EQ(chat.unreadMessagesAmount(), 0);
}

TEST(ChatTest, ReadChat){
    User first("Mickey");
    User second("Donald");
    Message msgFromFirst = first.writeMessage("Hi! I'm Mickey!!");
    Message msgFromSecond = second.writeMessage("Hi Mickey! my name is Donald.");

    Chat chat(first,second);
    chat.addMessage(msgFromFirst);
    chat.addMessage(msgFromSecond);

    ASSERT_EQ(chat.messagesAmount(),2);
    ASSERT_EQ(chat.unreadMessagesAmount(), 2);
    ASSERT_FALSE(chat.readChat("Pete"));
    ASSERT_TRUE(chat.readChat("Mickey"));
    ASSERT_EQ(chat.messagesAmount(),2);
    ASSERT_EQ(chat.unreadMessagesAmount(), 1); //Mickey read Donald's message
    ASSERT_TRUE(chat.readChat("Donald"));
    ASSERT_EQ(chat.messagesAmount(),2);
    ASSERT_EQ(chat.unreadMessagesAmount(), 0); //Donald read Mickey's message; no unread messages left
}

TEST(ChatTest, ChatCanOnlyBeUsedByItsMembers){
    User first("Mickey");
    User second("Donald");
    User third("Goofy");

    Message msgFromFirst = first.writeMessage("Hi! I'm Mickey!!");
    Message msgFromSecond = second.writeMessage("Hi Mickey! my name is Donald.");
    Message msgFromThird = third.writeMessage("Hello everyone! My name is Goofy!");

    Chat chat(first,third);
    chat.addMessage(msgFromFirst);
    chat.addMessage(msgFromSecond);
    chat.addMessage(msgFromThird);

    Message expectedFirst = chat.getMessage(0);
    Message expectedSecond = chat.getMessage(1);

    ASSERT_THAT(msgFromFirst.toString(),expectedFirst.toString());
    ASSERT_THAT(msgFromThird.toString(),expectedSecond.toString());
    ASSERT_FALSE(msgFromSecond.toString().compare(expectedSecond.toString()) == 0);
}

TEST(ChatTest, CheckParticipants){
    User first("Mickey");
    User second("Donald");
    User third("Goofy");

    Chat chat(first,second);
    ASSERT_TRUE(chat.checkParticipants("Mickey","Donald"));
    ASSERT_TRUE(chat.checkParticipants("Donald","Mickey"));
    ASSERT_FALSE(chat.checkParticipants("Mickey","Goofy"));
    ASSERT_FALSE(chat.checkParticipants("Goofy","Donald"));
}