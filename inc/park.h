#ifndef PARK_DEMO_PARK
#define PARK_DEMO_PARK

#include <algorithm>

namespace park_demo
{
    class Car;
    class Ticket;
    class ParkImpl;

    class Park {
    public:
        Park(int capacity);
        ~Park();

        int get_free_count();

        // Note: ticket should be released outside
        Ticket* park_car(Car* car);
        Car* pick_car(Ticket* ticket);

    private:
        ParkImpl* impl;
    };

    bool park_cmp(Park* p1, Park* p2);

    template<class T>
    T find_park(T begin, T end)
    {
        return std::max_element(begin, end, park_cmp);
    }
}

#endif