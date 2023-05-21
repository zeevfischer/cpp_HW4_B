#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"

namespace ariel
{
    class Cowboy:public Character
    {
    private:
        int bullets;
    public:
        Cowboy(string name ,Point location);
        // ~Cowboy();
        void shoot(Character *atack);
        bool hasboolets();
        void reload();
        
        //for test
        string print() override;
    };   
}
#endif