#include "Team.hpp"
#include <iostream>
using namespace std;
namespace ariel
{
    LeaderTeam::LeaderTeam(Character* leader)
    {
        this->leader = leader;//this need to point to leader
        this->members.push_back(leader);
    }
    void LeaderTeam::add(Character* newMember)
    {
        if(this->members.size() < 10)
        {
            this->members.push_back(newMember); //this needs fixing
            return;
        }
        throw "your teem is full";
    }
    int LeaderTeam::stillAlive()
    {
        int count =0;
        for(const auto &member : this->members)
        {
            if(member->GetLife() > 0)
            {
                    count ++;
            }
        }
        return count;
    }
    void LeaderTeam::attack(LeaderTeam* team)
    {

    }
    void LeaderTeam::print()
    {
        
    }
    vector<Character*> LeaderTeam::GetMembers()
    {
        return this->members;
    }
    Character* LeaderTeam::Getleader()
    {
        return this->leader;
    }


    //Team
    void Team::attack(LeaderTeam* team)
    {

    }
    void Team2::attack(LeaderTeam* team)
    {
        
    }
    void SmartTeam::attack(LeaderTeam* team)
    {
        
    }

}