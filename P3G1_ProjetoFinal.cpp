#include <iostream>
#include <vector>

using namespace std;

class User {
    private:
    string nome, email, telemovel;
    public:
    User(const string &nome, const string &email, const string &tele): nome(nome), email(email), telemovel(tele){}
};

class Msg {
    private:

    string info;

    public:

    Msg (const string &info): info(info){}
    virtual void getType()=0;
};

class EmailMsg: public Msg{
    private:
    static int n;
    unsigned int ID;

    public:
    EmailMsg(const string &info): Msg(info), ID(++n){}
};
int EmailMsg :: n = 1;


int main (){



}