#ifndef LEADERTEAM_HPP
#define LEADERTEAM_HPP
#include "Character.hpp"
#include "cowboy.hpp"
#include "Ninja.hpp"
#include "point.hpp"
#include <vector>
#include "Team.hpp"
namespace ariel
{
    class LeaderTeam
    {
        protected:
            vector<Character*> members;//<=10
            Character* leader;
        public:
            LeaderTeam(Character* leader);
            ~LeaderTeam();
            void add(Character* NewMember);
            int stillAlive();
            virtual void attack(LeaderTeam* team) = 0;
            void print();
    };
}
#endif