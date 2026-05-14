#include <iostream>
#include <string>
#include "User.h"
#include "Msg.h"
#include <fstream>
#include <vector>
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

    /*for (const auto &user : listaUtilizadores) {
        cout << "Nome: " << user.getNome() << ", Email: " << user.getEmail() << ", Telemóvel: " << user.getTelemovel() << endl;
    }*/

}
void printInfo(vector <User> &utilizadores) {
    for (const auto &u : utilizadores) {
        cout << "Nome: " << u.getNome() << ", Email: " << u.getEmail() << ", Telemóvel: " << u.getTelemovel() << endl;
    }
}
void InfoMsg(vector<Msg*> &mensagens) {
    int tipo;
    cout << "Tipo de mensagem (1-Email, 2-SMS): ";
    cin >> tipo;
    cin.ignore();
    string info, src, dst;
    cout << "Texto da mensagem: ";
    getline(cin, info);
    if (tipo == 1) {
        cout << "Email de origem: "; getline(cin, src);
        cout << "Email de destino: "; getline(cin, dst);
        mensagens.push_back(new EmailMsg(info, src, dst));
    } else if (tipo == 2) {
        cout << "Telemovel de origem: "; getline(cin, src);
        cout << "Telemovel de destino: "; getline(cin, dst);
        mensagens.push_back(new MobileMsg(info, src, dst));
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
    vector<Msg*> mensagens;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1 - Utilizador a partir de um ficheiro CSV" << endl;
        cout << "2 - Utilizador a partir do input" << endl;
        cout << "3 - Mensagem a partir de um ficheiro CSV" << endl; 
        cout << "4 - Mensagem a partir do input" << endl;          
        cout << "0 - Sair" << endl;                                 
        cout << "Opcao: ";
        
        cin >> escolha;
        cin.ignore(); 

        switch (escolha)
        {
        case 1:
            FileInput(utilizadores);
            break;
        case 2:
            InfoUser(utilizadores);
            break;
        case 3:
            FileMsgInput(mensagens); 
            break;
        case 4:
            InfoMsg(mensagens);      
            break;
        case 0:
            cout << "A sair..." << endl;
            break;
        default:
            cout << "Opcao invalida, tente de novo." << endl;
        }
    } while (escolha != 0);
    for(Msg* m : mensagens) {
        delete m;
    }
    mensagens.clear();
    return 0;
    



}