#include "park.h"
#include "car.h"
#include "ticket.h"

namespace park_demo
{

    class ParkImpl
    {
    public:
        ParkImpl(int cap)
        {
            capacity = cap;
        }
        ~ParkImpl()
        {

        }

        Ticket* park_car(Car* car)
        {
            return 0;
        }

        Car* pick_car(Ticket* ticket)
        {
            return 0;
        }

        int get_free_count()
        {
            return capacity;
        }

    private:

        int capacity;

    };

    Park::Park(int capacity)
    {
        impl = new ParkImpl(capacity);
    }

    Park::~Park()
    {
        delete impl;
    }

    Ticket* Park::park_car(Car* car)
    {
        return  impl->park_car(car);
    }

    Car* Park::pick_car(Ticket* ticket)
    {
        return impl->pick_car(ticket);
    }

    int Park::get_free_count()
    {
        return impl->get_free_count();
    }
}