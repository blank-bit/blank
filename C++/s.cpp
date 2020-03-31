#include <iostream>

using namespace std;
class Desk {
public:
	Desk(int, int);		//构造函数声明					
    void  outData() {
	cout << "Wight= " << weight << "\tHeight=" << high << endl;
	cout << "Lenght=" << length << "\tWidth=" << width << endl;
	}
private:
	int width,length, weight=2, high=3;
};
Desk::Desk(int w, int h) {		//构造函数定义					
	width = w;    length = h;
	cout << "call constructor  !" << endl;
}
int main() {
	Desk d(3, 5);
	d.outData();
    return 0;
}