#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <string>
using namespace std;
namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;
    public:
        Point(double val_x, double val_y);
        Point();
        // ~Point();
        const double distance(const Point& point) const;
        static Point moveTowards(const Point& origin ,const Point& dest,double length);
        
        //getters
        double get_x();
        double get_y();

        string print();
    };
}
#endif