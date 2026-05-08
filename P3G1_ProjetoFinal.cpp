#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class User {
    private:
    string nome, email, telemovel;
    public:
    User(const string &nome, const string &email, const string &tele): nome(nome), email(email), telemovel(tele){}

    string getNome() const { return nome; }
    string getEmail() const { return email; }
    string getTelemovel() const { return telemovel; }
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