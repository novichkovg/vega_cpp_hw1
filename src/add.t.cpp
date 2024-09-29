#include <gtest/gtest.h>
#include "add.h"

TEST(Test, Simple) {
	EXPECT_EQ(add(2,4), 6);
	EXPECT_EQ(add(2,0), 2);
	EXPECT_EQ(add(1,-1), 0);
}

int main (int argc, char ** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
