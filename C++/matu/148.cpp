#include <cstring>
#include <iostream>
using namespace std;
int i = 0;
class User {
   private:
    char name[10], pass[10];

   public:
    char Uname[10][10], Upass[10][10];
    User(const char *iname, const char *ipass) {
        strcpy(name, iname);
        strcpy(pass, ipass);
    }
    void AddUser(const char *iname, const char *ipass) {
        strcpy(Uname[i], iname);
        strcpy(Upass[i], ipass);
        i++;
    }
    int login(const char *name1, const char *pass1) {
        for (int j = 0; j < 10; j++) {
            if (strcmp(Uname[j], name1) == 0 && strcmp(Upass[j], pass1) == 0) {
                return j;
            }
        }
        return -1;
    }
};
int main() {
    char name[10], name1[10], pass[10], pass1[10];
    cin >> name >> pass >> name1 >> pass1;
    User user("LiWei", "liwei101");
    user.AddUser(name, pass);
    if (user.login(name1, pass1) >= 0) {
        cout << "Success Login!" << endl;
    } else {
        cout << "Login failed!" << endl;
    }
    return 0;
}
