#include "cowboy.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name,Point location):Character(location,110,name),bullets(6){}

    void Cowboy::shoot(Character *atack)
    {
        if(atack->isAlive() == false)
        {
            throw  "the enamy your attacking is dead";
        }
        atack->hit(10);
        this->bullets--;
    }
    bool Cowboy::hasboolets()
    {
        if(this->bullets > 0)
        {
            return true;

        }
        else
        {
            return false;
        }
    }
    void Cowboy::reload()
    {
        if(this->bullets > 0)
        {
            throw "you can still atack";
        }
        this->bullets = 6;
    }
    string Cowboy::print()
    {
        string print = "";
        print +=this->getName() + ": is a Cowboy\n";
        print += "life left: " + to_string(this->GetLife());
        print += "\nlocation: " + this->getLocation().print() + "\n";
        return print;
    }
}