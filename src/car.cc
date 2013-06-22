
#include "car.h"
#include <stdexcept>

namespace park_demo
{
    Car::Car()
    {
        park = 0;
    }

    Car::~Car()
    {

    }

    bool Car::is_parked()
    {
        return park != 0;
    }

    void Car::park_to(Park* p)
    {
        if (!p) {
            throw std::invalid_argument("park should exist");
        }

        if (is_parked()) {
            throw std::runtime_error("cannot park a car already parked");
        }
        park = p;
    }

    void Car::move_out()
    {
        if (!is_parked()) {
            throw std::runtime_error("cannot move out un-parked car");
        }

        park = 0;
    }

}
