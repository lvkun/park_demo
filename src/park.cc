#include "park.h"
#include "car.h"
#include "ticket.h"
#include <map>

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
            Ticket* ticket = new Ticket();
            map_tic_car[ticket] = car;
            return ticket;
        }

        // ticket should be released outside
        Car* pick_car(Ticket*& ticket)
        {
            return map_tic_car[ticket];
        }

        int get_free_count()
        {
            return capacity - map_tic_car.size();
        }

    private:

        int capacity;
        std::map<Ticket*, Car*> map_tic_car;

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