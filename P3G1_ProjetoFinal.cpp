#include <iostream>
/*<<<<<<< HEAD*/
#include <string>
#include "User.h"
#include "Msg.h"
#include <fstream>
#include <vector>
/*>>>>>>> 8bf08bd047f6c8af2b7e05284ddf72bca784ef0f*/

using namespace std;

/*class User {
    private:
    string nome, email, telemovel;
    public:
    User(const string &nome, const string &email, const string &tele): nome(nome), email(email), telemovel(tele){}
<<<<<<< HEAD
};*/
/*=======

    string getNome() const { return nome; }
    string getEmail() const { return email; }
    string getTelemovel() const { return telemovel; }
};*/
/*>>>>>>> 8bf08bd047f6c8af2b7e05284ddf72bca784ef0f*/

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
<<<<<<< HEAD
    string srcAddr;
    string dstAddr;

    public:
    EmailMsg(const string &info, const string &s, const string &d): Msg(info), ID(++n), srcAddr(s), dstAddr(d){}
    void getType() {
        cout << "Mensagem enviada por email." << endl;
    }
=======
    string srcAddr, dstAddr;

    public:
<<<<<<< HEAD

    EmailMsg(string info, unsigned int id): Msg(info), ID(id){}
=======
    EmailMsg(const string &info, const string &src, const string &dst): Msg(info), srcAddr(src), dstAddr(dst), ID(++n){}
>>>>>>> 703255279bc809b17430b2cf94cdc782f759baaa
>>>>>>> 8bf08bd047f6c8af2b7e05284ddf72bca784ef0f
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

void InfoUser(vector<User> &utilizadores){
    cout << "Introduza o nome do utilizador: ";
    string nome;
    cin >> nome;

    cout << "Introduza o email do utilizador: ";
    string email;
    cin >> email;

    cout << "Introduza o telemóvel do utilizador: ";
    string telemovel;
    cin >> telemovel;

    User user(nome, email, telemovel);
    utilizadores.push_back(user);
    cout << "Nome: " << user.getNome() << ", Email: " << user.getEmail() << ", Telemóvel: " << user.getTelemovel() << endl;
}

void FileInput(vector<User> &utilizadores){

    string file;
    cin.clear();
    cin >> file;
    ifstream ficheiro(file);
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
        cout << "Não foi possível abrir o ficheiro." << endl;
    }

    for (const auto &user : listaUtilizadores) {
        cout << "Nome: " << user.getNome() << ", Email: " << user.getEmail() << ", Telemóvel: " << user.getTelemovel() << endl;
    }

}

/*class MobileMsg : public Msg {

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

unsigned int MobileMsg::next_id = 1000;*/

int main (){

    int escolha;
    vector<User> utilizadores;
    do{
    cout<< "Escolha como quer introduzir os dados: "<<endl;
    cout<< "1 - A partir de um ficheiro CSV"<<endl;
    cout<< "2 - A partir do input do utilizador"<<endl;
    cin >> escolha;
    switch (escolha)
    {
    case 1:
    
        FileInput(utilizadores);
        
        break;
    
    case 2:

        InfoUser(utilizadores);

        break;
    }
} while (escolha != 1 && escolha != 2);

    
    return 0;
    



}