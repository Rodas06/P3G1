#include <iostream>
#include <string>
#include "User.h"
#include "Msg.h"
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

void InfoUser(vector<User> &utilizadores){
    cout << "Introduza o nome do utilizador: ";
    string nome;
    getline(cin, nome);

    cout << "Introduza o email do utilizador: ";
    string email;
    getline(cin,email);

    cout << "Introduza o telemóvel do utilizador: ";
    string telemovel;
    getline(cin, telemovel);

    User user(nome, email, telemovel);
    utilizadores.push_back(user);
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

}
void printInfo(vector <User> &utilizadores) {
    for (const auto &u : utilizadores) {
        cout << "Nome: " << u.getNome() << ", Email: " << u.getEmail() << ", Telemóvel: " << u.getTelemovel() << endl;
    }
}
void criarMensagem(vector<Msg*> &mensagens) {
    int tipo;
    cout << "Tipo de mensagem (1-Email, 2-SMS): ";
    cin >> tipo;
    cin.ignore();
    string texto, rem, dest;
    cout << "Mensagem:";
    getline(cin, texto);
    if (tipo == 1) {
        cout << "Email do/a remetente: ";
        getline(cin, rem);
        cout << "Email do/a destinatario/a:";
        getline(cin, dest);
        mensagens.push_back(new EmailMsg(texto, rem, dest));
    } else if (tipo == 2) {
        cout << "Telemovel do/a remetente: ";
        getline(cin, rem);
        cout << "Telemovel do/a destinatario/a: ";
        getline(cin, dest);
        mensagens.push_back(new MobileMsg(texto, rem, dest));
    }
    else {
        cout << "Erro. Tipo de mensagem invalido" << endl;
    }
}

void FileMsgInput(vector<Msg*> &mensagens) {
    string file;
    cout << "Nome do ficheiro de mensagens CSV: ";
    cin >> file;
    ifstream ficheiro(file);
    string linha;
    if (ficheiro.is_open()) {
        while (getline(ficheiro, linha)) {
            size_t p1 = linha.find(',');
            size_t p2 = linha.find(',', p1 + 1);
            size_t p3 = linha.find(',', p2 + 1);
            if (p1 != string::npos && p2 != string::npos && p3 != string::npos) {
                string tipo = linha.substr(0, p1);
                string info = linha.substr(p1 + 1, p2 - p1 - 1);
                string src = linha.substr(p2 + 1, p3 - p2 - 1);
                string dst = linha.substr(p3 + 1);
                if (tipo == "email") mensagens.push_back(new EmailMsg(info, src, dst));
                else if (tipo == "sms") mensagens.push_back(new MobileMsg(info, src, dst));
            }
        }
        ficheiro.close();
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