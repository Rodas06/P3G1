#ifndef USER_H
#define USER_H
#include <string>
#include <utility>

using namespace std;

class User {
private:
    string nome, email, telemovel;
public:
    User(string n, string e, string t) 
        : nome(std::move(n)), email(std::move(e)), telemovel(std::move(t)) {}

    string getNome() const { return nome; }
    string getEmail() const { return email; }
    string getTelemovel() const { return telemovel; }
};
#endif