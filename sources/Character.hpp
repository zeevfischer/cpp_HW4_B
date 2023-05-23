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
        bool in_game;
    public:
        Character(Point location,int life,string name);
        virtual ~Character() {};
        bool isAlive(); // life > 0
        double distance(const Character* other);
        void hit(int attack);//life - attack
        virtual string print() = 0; // need to fix 

        //getters
        string getName();
        Point getLocation();
        int GetLife();
        bool GetInGame();
        //setters
        void SetName(string name);
        void Setlocation(Point location);
        void Setlife(int life);
        void SetInGame(bool state);

        // tidy
        // Copy constructor
    Character(const Character& other)
        : location(other.location),
          life(other.life),
          name(other.name),
          in_game(other.in_game)
    {
    }

    // Copy assignment operator
    Character& operator=(const Character& other)
    {
        if (this == &other)
        {
            return *this;
        }
        // Perform member-wise assignment
        location = other.location;
        life = other.life;
        name = other.name;
        in_game = other.in_game;

        return *this;
    }

    // Move constructor
    Character(Character&& other) noexcept
        : location(other.location),
          life(other.life),
          name(move(other.name)),
          in_game(other.in_game)
    {
        // Reset the moved object
        other.life = 0;
        other.in_game = false;
    }

    // Move assignment operator
    Character& operator=(Character&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        // Perform member-wise move
        location = other.location;
        life = other.life;
        name = move(other.name);
        in_game = other.in_game;

        // Reset the moved object
        other.life = 0;
        other.in_game = false;

        return *this;
    }




    };
}
#endif