#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "point.hpp"
#include <string>
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        int life;
        string name;
    public:
        Character(Point location,int life,string name);
        Character();
        // ~Character();
        bool isAlive(); // life > 0
        double distance(const Character* other);
        void hit(int attack);//life - attack
        virtual string print() = 0;

        //getters
        string GetName();
        Point Getlocation();
        int GetLife();
        //setters
        void SetName(string name);
        void Setlocation(Point location);
        void Setlocation(int x,int y);
        void Setlife(int life);



    };
}
#endif