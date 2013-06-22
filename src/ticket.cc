
#include "ticket.h"

namespace park_demo
{
    Ticket::Ticket(Park* p)
    {
        park = p;
    }

    Ticket::~Ticket()
    {
        park = 0;
    }
}