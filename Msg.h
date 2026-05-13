#ifndef MSG_H
#define MSG_H
#include <string>
#include <iostream>
#include <utility>
using namespace std;
class Msg {
private:
    string info;
public:
    Msg(const string &info);
    virtual ~Msg() = default;
    virtual void getType() const = 0;
};

class EmailMsg : public Msg {
private:
    static int n;
    unsigned int ID;
    string srcAddr, dstAddr;
public:
    EmailMsg(const string &info, string s, string d): Msg(info), ID(++n), srcAddr(std::move(s)), dstAddr(std::move(d)){}
    void getType() const override {
        cout << "Mensagem enviada por email." << endl;
    }
    string getOrigem(){return srcAddr;}
    string getDest(){return dstAddr;}
};
int EmailMsg :: n = 1;

class MobileMsg : public Msg {
private:
    static int n;
    unsigned int ID;
    string srcPhoneNo, dstPhoneNo;
public:
    MobileMsg(const string &info, string src, string dst) : Msg(info), ID(++n), srcPhoneNo(std::move(src)), dstPhoneNo(std::move(dst)){}
    void getType() const override {
        cout << "Mensagem enviada por SMS." << endl;
    }
    string getNumOrigem(){return srcPhoneNo;}
    string getNumDest(){return dstPhoneNo;}
};
int MobileMsg :: n = 1000;
#endif
