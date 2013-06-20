#include "park.h"
#include "car.h"
#include "ticket.h"
#include <map>

namespace park_demo
{

    class ParkImpl
    {
    public:
        ParkImpl(Park* o, int cap)
        {
            capacity = cap;
            owner = o;
        }

        ~ParkImpl()
        {
            owner = 0;
        }

        Ticket* park_car(Car* car)
        {
            Ticket* ticket = new Ticket();
            map_tic_car[ticket] = car;
            car->park_to(owner);
            return ticket;
        }

        // ticket should be released outside
        Car* pick_car(Ticket*& ticket)
        {
            Car* car = map_tic_car[ticket];
            car->move_out();
            return car;
        }

        int get_free_count()
        {
            return capacity - map_tic_car.size();
        }

    private:

        Park* owner;
        int capacity;
        std::map<Ticket*, Car*> map_tic_car;

    };

    Park::Park(int capacity)
    {
        impl = new ParkImpl(this, capacity);
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