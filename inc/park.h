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

        Ticket* park_car(const Car& car);
        Car* pick_car(const Ticket& ticket);

    private:
        ParkImpl* impl;
    };
}

#endif