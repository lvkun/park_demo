
#include "gtest/gtest.h"
#include "park.h"
#include "car.h"
#include "ticket.h"

#include <stdexcept>
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

    delete ticket;
}

TEST(CAR, car_throw_exception_when_move_out_and_not_parked)
{
    Car car;
    EXPECT_THROW(car.move_out(), std::runtime_error);
}

TEST(CAR, car_throw_exception_when_park_if_parked)
{
    Car car;
    Park p(10);
    Ticket* ticket = p.park_car(&car);
    EXPECT_THROW(car.park_to(&p), std::runtime_error);

    delete ticket;
}

TEST(CAR, car_throw_exception_when_park_to_no_exist_park)
{
    Car car;
    EXPECT_THROW(car.park_to(0), std::invalid_argument);
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

TEST(PARK, park_free_count_is_not_changed_after_park_pick)
{
    Park p(10);
    Car* car = new Car();
    Ticket* ticket = p.park_car(car);
    Car* picked_car = p.pick_car(ticket);
    (void)picked_car;
    EXPECT_EQ(p.get_free_count(), 10);

    delete ticket;
    delete car;
}

TEST(PARK, park_create_throw_exception_when_capacity_is_not_valid)
{
    EXPECT_THROW(Park(0), std::invalid_argument);
}

TEST(PARK, park_throw_exception_when_park_car_exceed_capacity)
{
    Park p(3);

    Car car_one;
    Car car_two;
    Car car_three;
    Car car_four;

    Ticket* ticket_one = p.park_car(&car_one);
    Ticket* ticket_two = p.park_car(&car_two);
    Ticket* ticket_three = p.park_car(&car_three);

    EXPECT_THROW(p.park_car(&car_four), std::runtime_error);

    delete ticket_one;
    delete ticket_two;
    delete ticket_three;
}

TEST(PARK, park_throw_exception_when_using_ticket_not_from_this_park)
{
    Park park_one(3);
    Car car;
    Ticket* ticket = park_one.park_car(&car);

    Park park_two(3);
    EXPECT_THROW(park_two.pick_car(ticket), std::invalid_argument);
}
