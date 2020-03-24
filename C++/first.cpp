#include <iostream>
using namespace std;
int main()
{
	int *p1,*p2,*p3;
	p1=new int;     	//分配一个能够存放int类型数据的内存区域
	p2=new int(10);  	//分配一个int类型大小的内存区域，并将10存入其中
	p3=new int[10];  	//分配能够存放10个整数的数组区域
	if(!p3)                   //程序中常会见到这样的判定
		cout<<"allocation failure"<<endl;	//分配不成功显示错误信息
	*p1=5;	*p3=1;
	p3[1]=2;  p3[2]=3;  			//访问指向数组的数组元素
	cout<<"p1    address: "<<p1<<"  value: "<<*p1<<endl;
	cout<<"p2    address: "<<p2<<"  value: "<<*p2<<endl;
	cout<<"p3[0] address: "<<p3<<"  value: "<<*p3<<endl;
	cout<<"p3[1] address: "<<&p3[1]<<"  value: "<<p3[1]<<endl;
	delete p1; delete p2;   				//释放指向的内存
	//delete p3;        		//错误，只释放了p3指向数组的第1个元素
	delete []p3;        		//释放p3指向的数组
	return 0;
}
