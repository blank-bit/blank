// 设计一个User类，要求User类可以保持多个用户的用户名和密码信息，
// 实现User类的构造函数和AddUser方法添加新用户，
// 实现int login(char *name,char * pass)方法，该方法接受用户名和密码，
// 判断用户名对应的密码是否正确，如果正确返回用户的编号，如果不正确返回-1。

// User类的使用示意如下所示，在你的代码中除了实现User类以外，还需一如如下main函数

#include <iostream>
#include <cstring>

using namespace std;

int i = 0;
class User
{
private:
    char name[10];
    char pass[10];
public:
    char Uname[10][10], Upass[10][10];
    User(char* Name, char* Pass)
    {
        strcpy(name, Name);
        strcpy(pass, Pass);
    }
    void AddUser(char *Name, char *Pass)
    {
        strcpy(Uname[i], Name);
        strcpy(Upass[i], Pass);
        i++;
    }
    int login(char *name1,char * pass1)
    {
        for(int j = 0; j < 10; j++)
            if(strcmp(Uname[j], name1) == 0 && strcmp(Upass[j], pass1) == 0)
                return j;
     
        return -1;
    }
};

int main(){
	char name[10],name1[10],pass[10],pass1[10];
	cin>>name>>pass>>name1>>pass1;
	User user("LiWei","liwei101");
	user.AddUser(name,pass);
	if (user.login(name1,pass1) >=0)
	{
		cout<<"Success Login!"<<endl;
	}
	else{
		cout<<"Login failed!"<<endl;
	}
	return 0;
}