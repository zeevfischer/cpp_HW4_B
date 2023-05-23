#include "Team.hpp"
#include <iostream>
#include <numeric> 
using namespace std;
namespace ariel
{
    int max_int = std::numeric_limits<int>::max();
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
            if(member->isAlive() == true)
            {
                    count ++;
            }
        }
        return count;
    }
    vector<Character*> LeaderTeam::GetMembers()
    {
        return this->members;
    }
    Character* LeaderTeam::Getleader()
    {
        return this->leader;
    }
    //here i get a team and get a new leader from that team
    void LeaderTeam::SetNewLeader()
    {
        Character* temp = nullptr;
        double dist = max_int;
        for (auto member : this->members)
        {
            if(this->leader->distance(member) < dist && member->isAlive() == true && this->stillAlive() > 0)
            {
                temp  = member;
                dist = this->leader->distance(member);
            }
        }
        if(temp == nullptr)
        {
            throw runtime_error("all team is dead");
        }
        this->leader = temp;
    }
    //here i get a leader of the oposing team and find the closest opponent to that leader from this team
    Character* LeaderTeam::GetClosestMember(Character* leader)
    {
        Character* temp = nullptr;
        double dist = max_int;
        for (auto member : this->members)
        {
            if(leader->distance(member) < dist && member->isAlive() == true && this->stillAlive() > 0)
            {
                temp  = member;
                dist = leader->distance(member);
            }
        }
        return temp;
    }

    //Team
    void Team::attack(LeaderTeam* team)
    {
        if(team == nullptr)
        {
            throw invalid_argument("invalid_argument");
        }
        int round = 1;
        // first set leader for attacking team
        if(this->Getleader()->isAlive() == false)
        {
            this->SetNewLeader();
        }
        if(team->stillAlive() == 0)
        {
            throw runtime_error("team is dead");
        }
        //first cowboys round == 1 then ninjas round == 2
        for(unsigned long int i =0;i<this->GetMembers().size();i++)
        {
            auto member = this->GetMembers()[i];
            Character* temp = team->GetClosestMember(this->Getleader());
            if(temp == nullptr)
            {
                return;
            }
            if(Cowboy* test = dynamic_cast<Cowboy*>(member))
            {
                if(round == 1 && test->isAlive() == true)
                {
                    if(test->hasboolets() == true)
                    {
                        test->shoot(temp);
                    }
                    else
                    {
                        test->reload();
                    }
                }
            }
            if(Ninja* test = dynamic_cast<Ninja*>(member))
            {
                
                if(round == 2 && test->isAlive() == true)
                {
                    if(test->distance(temp) > 1)
                    {
                        test->move(temp);
                    }
                    else
                    {
                        test->move(temp);
                        test->slash(temp);
                    }
                }           
            }
            if(temp->isAlive() == false)
            {
                temp = team->GetClosestMember(this->Getleader());
            }
            if(i == this->GetMembers().size()-1 && round < 2)
            {
                round = 2;
                i = i-this->GetMembers().size();
            }
        }
    }

    void Team::print()
    {
        for (auto player: this->GetMembers())
        {
            if(Cowboy* test = dynamic_cast<Cowboy*>(player))
            {
                cout << test->print() << endl;
            }
        }
        for (auto player: this->GetMembers())
        {
            if(Ninja* test = dynamic_cast<Ninja*>(player))
            {
                cout << test->print() << endl;
            }
        }
    }
    void Team2::attack(LeaderTeam* team)
    {
        if(team == nullptr)
        {
            throw invalid_argument("invalid_argument");
        }
        if(this->Getleader()->isAlive() == false)
        {
            this->SetNewLeader();
        }
        if(team->stillAlive() == 0)
        {
            throw runtime_error("team is dead");
        }
        for(auto member : this->GetMembers())
        {
            if(member != nullptr && this->stillAlive() > 0)
            {
                Character* temp = team->GetClosestMember(this->Getleader());
                if(temp == nullptr)
                {
                    return;
                }
                if(Cowboy* test = dynamic_cast<Cowboy*>(member))
                {
                    if(test->isAlive()==true)
                    {
                        if(test->hasboolets() == true)
                        {
                            test->shoot(temp);
                        }
                        else
                        {
                            test->reload();
                        }
                    }
                }
                if(Ninja* test = dynamic_cast<Ninja*>(member))
                {
                    if(test->isAlive()==true)
                    {
                        if(test->distance(temp) > 1)
                        {
                            test->move(temp);
                        }
                        else
                        {
                            test->slash(temp);
                        }
                    }
                }
                if(temp->isAlive() == false)
                {
                    temp = team->GetClosestMember(this->Getleader());
                }
            }
        }
    }
    void Team2::print()
    {
        for (auto player: this->GetMembers())
        {
            if(Cowboy* test = dynamic_cast<Cowboy*>(player))
            {
                cout << test->print() << endl;
            }
            if(Ninja* test = dynamic_cast<Ninja*>(player))
            {
                cout << test->print() << endl;
            }
        }
    }
    void SmartTeam::attack(LeaderTeam* team)
    {
        
    }
    void SmartTeam::print()
    {

    }




    // tidy
}