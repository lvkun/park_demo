#include "park.h"
#include "car.h"
#include "ticket.h"

#include <map>
#include <stdexcept>

namespace park_demo
{

    class ParkImpl
    {
    public:
        ParkImpl(Park* o, int cap)
        {
            if (cap <= 0) {
                throw
                std::invalid_argument("capacity should be greater than 0");
            }

            capacity = cap;
            owner = o;
        }

        ~ParkImpl()
        {
            owner = 0;
        }

        Ticket* park_car(Car* car)
        {
            if (get_free_count() == 0) {
                throw std::runtime_error("no available space");
            }

            Ticket* ticket = new Ticket(owner);
            map_tic_car[ticket] = car;
            car->park_to(owner);
            return ticket;
        }

        Car* pick_car(Ticket* ticket)
        {
            std::map<Ticket*, Car*>::iterator it = map_tic_car.find(ticket);
            if (it == map_tic_car.end()) {
                throw
                std::invalid_argument("this ticket is not valid in this park");
            }

            Car* car = map_tic_car[ticket];
            map_tic_car.erase(ticket);
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