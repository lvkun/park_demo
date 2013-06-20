
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

}
