#ifndef PARK_DEMO_TICKET
#define PARK_DEMO_TICKET

namespace park_demo
{
    class Park;
    class Ticket {
    public:
        Ticket(Park* p);
        ~Ticket();
    private:
        Park* park;

    };
}

#endif