#include "Character.hpp"
#include <math.h>

namespace ariel{
    Character::Character(Point location , int life, string name)
    {
        this->location = location;
        this->life = life;
        this->name = name;
    }
    Character::~Character()
    {
    }
    bool Character::isAlive(){
        if(this->life > 0)
        {
            return true;
        }
        return false;
    }
    double Character::distance(const Character* player)
    {
        if(player == nullptr)
        {
            throw ("player is null");
        }
        else
        {
            return this->location.distance(player->location);
        }
    }
    void Character::hit(int damage)
    {
        this->life -= damage;
    }
    string Character::print()
    {
        string out;
        out += "name: " + this->name;
        out += "\nlife: " + this->name;
        out += "\nlocation " + this->location.print();
        return out;
    }   
    //getters
    string Character::getName()
    {
        return this->name;
    }
    Point Character::getLocation()
    {
        return this->location;
    }
    int Character::GetLife()
    {
        return this->life;
    }
    bool Character::GetInGame()
    {
        return this->in_game;
    }
    //setters
    void Character::Setlife(int life)
    {
        this->life = life;
    }
    void Character::SetName(string name)
    {
        this->name = name;
    }
    void Character::Setlocation(Point location)
    {
        Point p(location.get_x(),location.get_y());
        this->location = p;
    }
    void Character::Setlocation(int x,int y)
    {
        Point p(x,y);
        this->location = p;
    }
    void Character::SetInGame(bool state)
    {
        this->in_game = state;
    }

}