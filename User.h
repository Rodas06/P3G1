#pragma once
#include <string>
#include <iostream>
using namespace std;
class User {
private:
string nome, email, telemovel;
public:
    User( string &nome, string &email, string &tele): nome(nome), email(email), telemovel(tele){}
    string getNome() { return nome; }
    string getEmail() { return email; }
    string getTelemovel() { return telemovel; }
};
