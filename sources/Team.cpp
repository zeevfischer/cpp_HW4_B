#include "Team.hpp"
#include <iostream>
using namespace std;
namespace ariel
{
    LeaderTeam::LeaderTeam(Character* leader) : leader(leader)
    {
        if(leader->GetInGame() == true)
        {
            throw runtime_error("player is alredy in game");
        }
        this->add(leader);
    }
    LeaderTeam::~LeaderTeam()
    {
        for(auto member : this->members)
        {
            delete member;
        }
        this->members.clear();
    }
    void LeaderTeam::add(Character* newMember)
    {
        if(this->members.size() < 10 && newMember != nullptr && newMember->isAlive() == true && newMember->GetInGame() == false)
        {
            this->members.push_back(newMember);
            newMember->SetInGame(true);
            return;
        }
        throw runtime_error("your teem is full");
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
    void LeaderTeam::print()
    {
        for (auto player: this->members)
        {
            player->print();
        }
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