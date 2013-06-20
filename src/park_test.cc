
#include "gtest/gtest.h"
#include "park.h"
#include "car.h"

TEST(CAR, car_is_not_parked_when_create)
{
    park_demo::Car car;
    EXPECT_FALSE(car.is_parked());
}

TEST(PARK, park_create_free_count_equal_capacity)
{
    park_demo::Park p(10);
    EXPECT_EQ(p.get_free_count(), 10);
}
