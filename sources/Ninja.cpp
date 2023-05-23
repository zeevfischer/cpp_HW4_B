#include "Ninja.hpp"
#include "Character.hpp"
#include "point.hpp"
#include <string>

using namespace std;
namespace ariel
{
    //Ninja
    Ninja::Ninja(Point location,string name,int life,int speed):Character(location,life,name),speed(speed){}
    void Ninja::slash(Character* opponent)
    {
        if(this == opponent)
        {
            throw runtime_error("cnat attack yourself");
        }
        if(opponent->isAlive() == false)
        {
            throw  runtime_error("the enamy your attacking is dead");
        }
        if(this->GetLife() <= 0)
        {
            throw  runtime_error("this player is dead");
        }
        if(this->distance(opponent) <= 1)
        {
            opponent->hit(40);
        }
    }
    void Ninja::move(Character *opponent)
    {
        Point temp = Point::moveTowards(this->getLocation(),opponent->getLocation(),this->speed);
        this->Setlocation(temp);
    }
    int Ninja::getSpeed()
    {
        return this->speed;
    }
    void Ninja::setSpeed(int speed)
    {
        this->speed = speed;
    }
    string Ninja::print()
    {
        string print = "";
        print +=this->getName() + ": is a Ninja\n";
        print += "life left: " + to_string(this->GetLife());
        print += "\nlocation: " + this->getLocation().print();
        return print;
    }

    //OldNinja constructor
    OldNinja::OldNinja(string name, Point location)
        : Ninja(location, name, 150, 8) {}

    //TrainedNinja constructor
    TrainedNinja::TrainedNinja(string name, Point location)
        : Ninja(location, name, 120, 12) {}

    //YountNinja constructor
    YoungNinja::YoungNinja(string name, Point location)
        : Ninja(location, name, 100, 14) {}
}