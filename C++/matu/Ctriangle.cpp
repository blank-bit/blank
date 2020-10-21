// 实现一个三角形类 Ctriangle 
// 该类有一个GetPerimeter方法返回三角形的周长;
// GetArea方法返回三角行的面积;
// 该类还提供一个display方法显示三角形的三边长度;

// 最终在main函数中生成该类，
// 输入三条边的长度（不用考虑三条边不能构成三角形的情况）;
// 展示三角形的三边长度以及周长和面积

// Ctriangle类的使用如下，在你的代码中除了实现Ctriangle类还需引入一下代码。

#include <iostream>
#include <math.h>
using namespace std;

class Ctriangle
{
private:
    double x;
    double y;
    double z;
public:
    Ctriangle(double x,double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    double GetPerimeter()
        {return (x + y + z);}
    double GetArea()
    {
        return 0.25 * sqrt((x + y + z) * (x + y - z) * (x + z - y) * (y + z - x));
    }
    void display()
    {
        cout << "Ctriangle:a=" << x << ",b=" << y << ",c=" << z << endl;
    }
};


int main(){
	double a,b,c;
	cin>>a>>b>>c;
	Ctriangle T(a,b,c);
	T.display();
	cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
	cout<<"Area:"<<T.GetArea()<<endl;
	return 0;	 
}