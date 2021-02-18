#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../classes/User.h"
#include "../classes/Chat.h"

using namespace std;

TEST(ChatTest, MessageInsertion){
    User first("Mickey");
    User second("Donald");
    Message msgFromFirst = first.writeMessage("Hi! I'm Mickey!!");
    Message msgFromSecond = second.writeMessage("Hi Mickey! my name is Donald.");
    Chat chat(first,second);
    chat.addMessage(msgFromFirst);
    chat.addMessage(msgFromSecond);
    vector<Message>::iterator it = chat.getMessages();
    Message expectedFirst = *it++;
    Message expectedSecond = *it;
    ASSERT_THAT(msgFromFirst.toString(),expectedFirst.toString());
    ASSERT_THAT(msgFromSecond.toString(),expectedSecond.toString());
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

    vector<Message>::iterator it = chat.getMessages();
    Message expectedFirst = *it++;
    Message expectedSecond = *it;

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