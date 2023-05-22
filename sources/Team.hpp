#ifndef TEAM_HPP
#define TEAM_HPP
// #include "LeaderTeam.hpp"
#include "Character.hpp"
#include "cowboy.hpp"
#include "Ninja.hpp"
#include "point.hpp"
#include <vector>
namespace ariel{
    class LeaderTeam
    {
        private:
            vector<Character*> members;//<=10
            Character* leader;
        public:
            LeaderTeam(Character* leader);
            virtual ~LeaderTeam();
            void add(Character* NewMember);
            int stillAlive();
            virtual void attack(LeaderTeam* team) = 0;
            void print();
            //my functions
            vector<Character*> GetMembers();
            Character* Getleader();
            Character* GetNewLeader(LeaderTeam* team);
    };

    class Team:public LeaderTeam
    {
        public:
            Team(Character* leader):LeaderTeam(leader){}
            void attack(LeaderTeam* team) override;
    };

    class Team2:public LeaderTeam
    {
        public:
            Team2(Character* leader):LeaderTeam(leader){}
            void attack(LeaderTeam* team) override;

    };
    class SmartTeam:public LeaderTeam
    {
        public:
            SmartTeam(Character* leader):LeaderTeam(leader){}
            void attack(LeaderTeam* team) override;

    };
}
#endif