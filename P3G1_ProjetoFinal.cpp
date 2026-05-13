#include <iostream>
#include <string>
#include "User.h"

using namespace std;

/*class User {
    private:
    string nome, email, telemovel;
    public:
    User(const string &nome, const string &email, const string &tele): nome(nome), email(email), telemovel(tele){}
};*/

class Msg {
    private:
    string info;

    public:
    Msg (const string &info): info(info){}
    virtual void getType()=0;
    virtual ~Msg();
};

class EmailMsg: virtual public Msg{
    private:
    static int n;
    unsigned int ID;
    string srcAddr;
    string dstAddr;

    public:
    EmailMsg(const string &info, const string &s, const string &d): Msg(info), ID(++n), srcAddr(s), dstAddr(d){}
    void getType() {
        cout << "Mensagem enviada por email." << endl;
    }
};
int EmailMsg :: n = 1;


int main (){



}