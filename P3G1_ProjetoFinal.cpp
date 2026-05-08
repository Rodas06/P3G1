#include <iostream>
#include <fstream>
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
    string srcAddr, dstAddr;

    public:
    EmailMsg(const string &info, const string &src, const string &dst): Msg(info), srcAddr(src), dstAddr(dst), ID(++n){}
};
int EmailMsg :: n = 1;

class MobileMsg: public Msg{
    private:
    static int n;
    unsigned int ID;
    string srcPhoneNo, dstPhoneNo;

    public:
    MobileMsg(const string &info, const string &src, const string &dst): Msg(info), srcPhoneNo(src), dstPhoneNo(dst), ID(++n){}
};
int MobileMsg :: n = 1000;

int main (){

    ifstream ficheiro("utilizadores.csv");
    string linha;
    vector<User> listaUtilizadores;

    if (ficheiro.is_open()) {
        while (getline(ficheiro, linha)) {
            size_t pos1 = linha.find(',');
            size_t pos2 = linha.find(',', pos1 + 1);

            string nome = linha.substr(0, pos1);
            string email = linha.substr(pos1 + 1, pos2 - pos1 - 1);
            string telemovel = linha.substr(pos2 + 1);

            listaUtilizadores.emplace_back(nome, email, telemovel);
        }
        ficheiro.close();
    } else {
        cerr << "Não foi possível abrir o ficheiro." << endl;
    }

    



}