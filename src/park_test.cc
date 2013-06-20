
#include "gtest/gtest.h"
#include "park.h"

TEST(PARK, park_init)
{
    park_demo::Park p(10);
    EXPECT_EQ(p.get_free_count(), 10);
}