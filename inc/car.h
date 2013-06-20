#ifndef PARK_DEMO_CAR
#define PARK_DEMO_CAR

namespace park_demo {

    class Park;
    class Car {
    public:
        Car();
        ~Car();

        void park_to(Park* p);
        void move_out();

        bool is_parked();

    private:
        Park* park;
    };

}


#endif