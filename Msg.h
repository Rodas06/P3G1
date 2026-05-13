#ifndef MSG_H
#define MSG_H
#include <string>
#include <iostream>
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
    EmailMsg(const string &info, const string &src, const string &dst);
    void getType() const override {
        cout << "Mensagem enviada por email." << endl;
    };
};

class MobileMsg : public Msg {
private:
    static int n;
    unsigned int ID;
    string srcPhoneNo, dstPhoneNo;
public:
    MobileMsg(const string &info, const string &src, const string &dst);
    void getType() const override {
        cout << "Mensagem enviada por SMS." << endl;
    };
};
#endif
