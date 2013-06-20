
#include "car.h"

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
        park = p;
    }

    void Car::move_out()
    {
        park = 0;
    }

}
