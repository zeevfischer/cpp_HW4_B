#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;

TEST_SUITE("Point Class")
{
    TEST_CASE("Point init")
    {
        Point p(1.5, 2.5);
        CHECK(p.get_x() == 1.5);
        CHECK(p.get_y() == 2.5);
    }
    TEST_CASE("distance") 
    {
        Point p1(2, 8);
        Point p2(5, 8);
        CHECK(p1.distance(p2) == 3);
        CHECK(p2.distance(p1) == 3);
    }
    TEST_CASE("moveTowards") 
    {
        Point p1(2, 8);
        Point p2(5, 8);

        Point temp1 = moveTowards(p1,p2,8);
        CHECK(temp1.get_x() == 5);
        CHECK(temp1.get_y() == 8);

        Point temp2 = moveTowards(p2,p1,8);
        CHECK(temp2.get_x() == 2);
        CHECK(temp2.get_y() == 8);
    }
}
namespace ariel 
{
    class testCharacter:public Character
    {
        public:
            testCharacter(Point location, int life ,string name) 
            : Character(location, life, name) {}

            string print() override
            {
                return "test function";
            }
    };
}
TEST_SUITE("Character")
{
    TEST_CASE("isAlive") 
    {
        Point location(0, 0);
        int life = 100;
        string name = "bond";
        testCharacter test(location, life, name);
        CHECK(test.isAlive() == true);
        test.hit(life);
        CHECK(test.isAlive() == false);
    }

    TEST_CASE("distance") 
    {
        Point location1(2, 8);
        Point location2(5, 8);
        int life = 100;
        string name = "james";
        testCharacter test1(location1, life, name);
        testCharacter test2(location2, life, name);
        CHECK(test1.distance(&test2) == 3.0);
        CHECK(test2.distance(&test1) == 3.0);
    }

    TEST_CASE("hit") 
    {
        Point location(0, 0);
        int life = 100;
        string name = "bond";
        testCharacter test(location, life, name);
        int damage = 50;
        test.hit(damage);
        CHECK(test.isAlive() == true);
        CHECK(test.GetLife() == (50));
    }

    TEST_CASE("getters") {
        Point location(0, 0);
        int life = 100;
        string name = "alice";
        testCharacter test(location, life, name);
        CHECK(test.GetName() == name);
        CHECK(test.Getlocation().get_x() == 0);
        CHECK(test.Getlocation().get_y() == 0);
        CHECK(test.GetLife() == 100);
    }
}
TEST_SUITE("Cowboy")
{
    TEST_CASE("shoot , hasboolets , reload")
    {
        Point point1(2, 8);
        Point point2(5, 8);
        Cowboy player1("rick",point1);
        Cowboy player2("morty",point2);
        CHECK(player1.hasboolets());
        while (player1.hasboolets())
        {
            player1.shoot(&player2);    
        }
        CHECK_FALSE(player1.hasboolets());
        player1.reload();
        CHECK(player1.hasboolets());
    }
}
namespace ariel 
{
    class testNinja:public Ninja
    {
        public:
            testNinja(Point location,string name,int life,int speed) 
            : Ninja(location,name,life,speed) {}

            string print() override
            {
                return "test function";
            }
    };
}
TEST_SUITE("Ninja"){
    TEST_CASE("move") {
        Point point1(2, 8);
        Point point2(5, 8);
        testNinja Ninja1(point1,"one fish",100,10);
        testNinja Ninja2(point2,"tew fish",100,10);
        
        double dist = Ninja1.distance(&Ninja2);
        Ninja1.move(&Ninja2);
        double newDist = Ninja1.distance(&Ninja2);
        CHECK(newDist < dist);

        CHECK(Ninja1.Getlocation().get_x() != 2);
        CHECK(Ninja1.Getlocation().get_y() == 8);
    }

    TEST_CASE("slash") {
        Point point1(2, 8);
        Point point2(5, 8);
        testNinja Ninja1(point1,"red fish",100,10);
        testNinja Ninja2(point2,"blue fish",100,10);
        int life1 = Ninja2.GetLife();
        Ninja1.slash(&Ninja2);
        int life2 = Ninja2.GetLife();
        CHECK(life1 >= life2);
    }
}
TEST_SUITE("Ninja classification")
{
    TEST_CASE("OldNinja")
    {
        Point location{0,0};
        OldNinja player{"OldNinja", location};
        CHECK(player.GetName() == "OldNinja");
        CHECK(player.Getlocation().get_x() == 0);
        CHECK(player.Getlocation().get_y() == 0);
        CHECK(player.isAlive());
        CHECK(player.GetLife() == 140);
        CHECK(player.getSpeed() == 8);
    }
    TEST_CASE("TrainedNinja")
    {
        Point location{0,0};
        TrainedNinja player{"TrainedNinja", location};
        CHECK(player.GetName() == "TrainedNinja");
        CHECK(player.Getlocation().get_x() == 0);
        CHECK(player.Getlocation().get_y() == 0);
        CHECK(player.isAlive());
        CHECK(player.GetLife() == 120);
        CHECK(player.getSpeed() == 12);
    }
    TEST_CASE("YoungNinja")
    {
        Point location{0,0};
        OldNinja player{"YoungNinja", location};
        CHECK(player.GetName() == "YoungNinja");
        CHECK(player.Getlocation().get_x() == 0);
        CHECK(player.Getlocation().get_y() == 0);
        CHECK(player.isAlive());
        CHECK(player.GetLife() == 100);
        CHECK(player.getSpeed() == 14);
    }
}
TEST_SUITE("Team")
{
    TEST_CASE("baisic")
    {
        Cowboy* player1 = new Cowboy("alex" , Point(1,2));
        Cowboy* player2 = new Cowboy("alex" , Point(3,2));
        Cowboy* player3 = new Cowboy("alex" , Point(5,2));

        Team test1(player1);
        Team test2(player3);
        test1.add(player2);
        CHECK(test1.stillAlive() == 2);
        while(test1.stillAlive() != 0)
        {
            test2.attack(&test1);
        }
        CHECK(test1.stillAlive() == 0);
    }
}