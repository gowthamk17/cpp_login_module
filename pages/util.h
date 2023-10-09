#include <string>

using std::string;

#ifndef UTILITY_H
#define UTILITY_H

class User {
    string password;
    public:
        string username;
        User() {
            
        }
        User(string name, string psw){
            username = name;
            password = psw;
        }
        void setPass(string psw){
            password = psw;
        }
        string getPass() {
            return password;
        }
};



#endif