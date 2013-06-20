#ifndef PARK_DEMO_CAR
#define PARK_DEMO_CAR

namespace park_demo {

    class Park;
    class Car {
    public:
        Car();
        ~Car();

        bool is_parked();

    private:
        Park* park;
    };

}


#endif