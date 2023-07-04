#include "Fixed.hpp"

class Point{
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point& p);
    Point& operator=(const point& p);
    ~Point(void);
    bool bsp(const Point a, const Point b, const Point c, Point const Point);
private:
    const Fixed x;
    const Fixed y;
};