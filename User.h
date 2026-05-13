#pragma once
#include <string>
#include <iostream>
using namespace std;
class User {
private:
string nome, email, telemovel;
public:
User(const string &nome, const string &email, const string &tele): nome(nome), email(email), telemovel(tele){}
};
