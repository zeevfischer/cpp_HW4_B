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

            // tidy
            // Copy Constructor:
            LeaderTeam(const LeaderTeam& other) :members(other.members),leader(other.leader){}
            // Copy Assignment Operator:
            LeaderTeam& operator=(const LeaderTeam& other) 
            {
                if (this != &other) {
                    // Copy members vector
                    members = other.members;

                    // Copy leader pointer
                    leader = other.leader;
                }
                return *this;
            }
            // Move Constructor:
            LeaderTeam(LeaderTeam&& other) noexcept :members(std::move(other.members)),leader(other.leader)
            {
                other.leader = nullptr;
            }
            // Move Assignment Operator:
            LeaderTeam& operator=(LeaderTeam&& other) noexcept 
            {
                if (this != &other) {
                    // Move members vector
                    members = std::move(other.members);

                    // Move leader pointer
                    leader = other.leader;
                    other.leader = nullptr;
                }
                return *this;
            }
        
    };

    class Team:public LeaderTeam
    {
        public:
            Team(Character* leader):LeaderTeam(leader){}
            void attack(LeaderTeam* team) override;
            void print() override;
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