#ifndef SUPPORTTROOP_H
#define SUPPORTTROOP_H
#include <string>


class Support_troop : public Troop {
    private:
    std::string Buff_type;

    public:
    std::string Get_Buff_type();
};

#endif
