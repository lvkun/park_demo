
#include "gtest/gtest.h"
#include "park.h"
#include "car.h"
#include "ticket.h"

using namespace park_demo;

TEST(CAR, car_is_not_parked_when_create)
{
    Car car;
    EXPECT_FALSE(car.is_parked());
}

TEST(CAR, car_is_parked_after_park_car)
{
    Park p(10);
    Car car;
    p.park_car(&car);
    EXPECT_TRUE(car.is_parked());
}

TEST(CAR, car_is_not_parked_after_pick_car)
{
    Park p(10);
    Car car;
    Ticket* ticket = p.park_car(&car);
    p.pick_car(ticket);
    EXPECT_FALSE(car.is_parked());
}

TEST(PARK, park_create_free_count_equal_capacity)
{
    Park p(10);
    EXPECT_EQ(p.get_free_count(), 10);
}

TEST(PARK, park_free_count_reduce_after_park_car)
{
    Park p(10);
    Car car;
    p.park_car(&car);
    EXPECT_EQ(p.get_free_count(), 9);
}

TEST(PARK, park_car_is_not_changed_after_park_pick)
{
    Park p(10);
    Car* car = new Car();
    Ticket* ticket = p.park_car(car);
    Car* picked_car = p.pick_car(ticket);
    EXPECT_EQ(car, picked_car);

    delete ticket;
    delete car;
}
