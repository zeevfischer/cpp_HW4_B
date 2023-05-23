#include "Cowboy.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name,Point location):Character(location,110,name),bullets(6){}
    // Character::Character(const Character& other)
    // : location(other.location), life(other.life), name(other.name), in_game(other.in_game) {
    // // No need for deep copying since the member variables are of primitive types (int, string, bool)
    // }
    void Cowboy::shoot(Character *atack)
    {
        if(this == atack)
        {
            throw runtime_error("cnat attack yourself");
        }
        if(atack->isAlive() == false)
        {
            throw  runtime_error("the enamy your attacking is dead");
        }
        if(this->GetLife() < 0)
        {
            throw  runtime_error("this player is dead");
        }
        if(this->bullets > 0)
        {
            atack->hit(10);
            this->bullets--;
        }
        // else
        // {
        //     throw "you have no bullets";
        // }
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
        // if(this->bullets > 0)
        // {
        //     throw "you can still atack";
        // }
        if(this->GetLife() <= 0)
        {
            throw runtime_error("this player is dead and cant reload");
        }
        this->bullets = 6;
    }
    string Cowboy::print()
    {
        string print = "";
        print +=this->getName() + ": is a Cowboy\n";
        print += "life left: " + to_string(this->GetLife());
        print += "\nlocation: " + this->getLocation().print();
        return print;
    }
}