#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double a, b;

public:
    Point(double a, double b);
    double Geta() { return a; }
    double Getb() { return b; }
    double Distance(const Point &p)
    {
        a -= p.a;
        b -= p.b;
        return sqrt(a * a + b * b);
    }
};

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Point A(a, b), B(c, d);
    cout << A.Distance(B) << endl;
    return 0;
}

Point::Point(double a, double b)
{
    this->a = a;
    this->b = b;
}