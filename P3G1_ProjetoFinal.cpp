#include <iostream>
#include <vector>

using namespace std;

class User {

    private:
    string Nome, Email, Telemovel;

    public:

    User(string nome, string email, string tele): Nome(nome), Email(email), Telemovel(tele){}
    
};

class Msg {
    private:

    string Info;

    public:

    Msg (string info): Info(info){}

    virtual void getType()=0;
};

class EmailMsg: public Msg{

    private:

    unsigned int ID;

    public:

    EmailMsg(string info, unsigned int id): Msg(info), ID(id){}

    

};

int main (){



}