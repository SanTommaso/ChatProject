
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../classes/User.h"

using namespace std;

TEST(UserTest, UserIDAssignment){
    User firstUser("Mickey");
    User secondUser("Donald");
    User thirdUser("Goofy");

    ASSERT_EQ(1, firstUser.getUserID());
    ASSERT_EQ(2, secondUser.getUserID());
    ASSERT_EQ(3, thirdUser.getUserID());
}