#include "park.h"
#include "car.h"
#include "ticket.h"

namespace park_demo
{

    class ParkImpl
    {
    public:
        ParkImpl(int capacity)
        {

        }
        ~ParkImpl()
        {

        }

        Ticket* park_car(const Car& car)
        {
            return 0;
        }

        Car* pick_car(const Ticket& ticket)
        {
            return 0;
        }

    private:

    };

    Park::Park(int capacity)
    {
        impl = new ParkImpl(capacity);
    }

    Park::~Park()
    {
        delete impl;
    }

    Ticket* Park::park_car(const Car& car)
    {
        return  impl->park_car(car);
    }

    Car* Park::pick_car(const Ticket& ticket)
    {
        return impl->pick_car(ticket);
    }
}