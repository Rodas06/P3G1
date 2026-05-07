#include <iostream>
#include <vector>
#include <string>

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

class MobileMsg : public Msg {

private:
    static unsigned int next_id;
    unsigned int id;
    string srcPhoneNo;
    string dstPhoneNo;

public:
    MobileMsg(std::string info_param, std::string src, std::string dst)
        : Msg(info_param), srcPhoneNo(src), dstPhoneNo(dst) {

        id = next_id++;
    }

    string getType() const {
        return "MobileMsg";
    }

    unsigned int getId() const { return id; }
    string getSrcPhoneNo() const { return srcPhoneNo; }
    string getDstPhoneNo() const { return dstPhoneNo; }
};

unsigned int MobileMsg::next_id = 1000;

int main (){



}