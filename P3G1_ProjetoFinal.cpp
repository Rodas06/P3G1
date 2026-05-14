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