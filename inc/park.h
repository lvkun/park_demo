#ifndef PARK_DEMO_PARK
#define PARK_DEMO_PARK

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

        Ticket* park_car(Car* car);
        Car* pick_car(Ticket* ticket);

    private:
        ParkImpl* impl;
    };
}

#endif