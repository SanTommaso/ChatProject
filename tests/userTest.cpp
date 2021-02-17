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