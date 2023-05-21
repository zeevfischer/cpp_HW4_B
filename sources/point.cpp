#include "point.hpp"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
namespace ariel
{
    Point::Point(double a,double b)
    {
        this->x = a;
        this->y = b;
    }
    Point::Point()
    {}
    //d = sqr(x1-x2)^2 + (y1-y2)^2
    const double Point::distance(const Point& p) const
    {
        double dist = 0;
        double pow_X = pow(this->x - p.x,2);
        double pow_y = pow(this->y - p.y,2);
        dist = abs(sqrt(pow_X+pow_y));
        return dist;
    }
    Point Point::moveTowards(const Point &origin,const Point &dest, double length)
    {
        
        // double dist = Point::my_dist(origin,dest);
        double dist = origin.distance(dest);
        if(dist < length)
        {
            return dest;
        }
        else
        {
            // google function
            double normalizedDx = (dest.x - origin.x) / dist;
            double normalizedDy = (dest.y - origin.y) / dist;
            Point newPoint(origin.x + (normalizedDx * length),origin.y + (normalizedDy * length));
            return newPoint;
        }
    }
    double Point::get_x()
    {
        return this->x;
    }
    double Point::get_y()
    {
        return this->y;
    }
    string Point::print()
    {
        return  "(" + to_string(this->get_x()) + "," + to_string(this->get_y()) + ")" ;
    }
}