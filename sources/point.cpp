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
        // cout << "dest: "<<"(" << dest.x << "," << dest.y << ")" << endl; 
        // cout << "origin: "<<"(" << origin.x << "," << origin.y << ")" << endl; 
        // cout << endl;
        if(length == 0)
        {
            return origin;
        }
        if(length < 0)
        {
            throw invalid_argument("distance cant be less then 0");
        }
        double dist = origin.distance(dest);
        if(dist < length)
        {
            // cout << "out put: (" << dest.x << "," << dest.y << ")" << endl;
            return dest;
        }
        else
        {
            // google function
            double normalizedDx = (dest.x - origin.x) / dist;
            double normalizedDy = (dest.y - origin.y) / dist;
            Point newPoint(origin.x + (normalizedDx * length),origin.y + (normalizedDy * length));
            // cout << "out put: "<<newPoint.print()<<endl;
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