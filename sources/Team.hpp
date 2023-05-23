#ifndef TEAM_HPP
#define TEAM_HPP
// #include "LeaderTeam.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
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
            virtual void print() = 0;
            //my functions
            vector<Character*> GetMembers();
            Character* Getleader();
            void SetNewLeader();
            Character* GetClosestMember(Character* leader);
    };

    class Team:public LeaderTeam
    {
        public:
            Team(Character* leader):LeaderTeam(leader){}
            void attack(LeaderTeam* team) override;
            virtual void print() override;
    };

    class Team2:public Team
    {
        public:
            Team2(Character* leader):Team(leader){}
            void attack(LeaderTeam* team) override;
            void print() override;

    };
    class SmartTeam:public LeaderTeam
    {
        public:
            SmartTeam(Character* leader):LeaderTeam(leader){}
            void attack(LeaderTeam* team) override;
            void print() override;

    };
}
#endif