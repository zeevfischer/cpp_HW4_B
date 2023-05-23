#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel{
    class Ninja:public Character
    {
        private:
            int speed;
        public:
            Ninja(Point location,string name,int life, int speed);
            // ~Ninja();
            void move(Character* opponent);
            void slash(Character* opponent);

            //for tests
            int getSpeed();
            void setSpeed(int speed);
            string print() override;
    };
    //Ninja classification
    /*
        all the Ninjas have the same functions and parameters the only difference is the value 
        youngNinja speed 14 life 100
        Traind speed 12 life 120
        old speed 8 life 150 
    */
    class OldNinja:public Ninja{
        public:
            OldNinja(string name, Point location);
    };

    class TrainedNinja:public Ninja{
        public:
            TrainedNinja(string name, Point location);
    };
    
    class YoungNinja:public Ninja{
        public:
            YoungNinja(string name, Point location);
    };
}
#endif