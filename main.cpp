#include <iostream>
#include <fstream>
#include "pages/homepage.h"

int main(int, char**){
    try{
        std::fstream file("users.csv");
        std::string userdata;
        while(std::getline(file, userdata)) {
            char delimeter = ',';
            size_t pos = userdata.find(delimeter);
            if(pos != std::string::npos) {
                std::string username = userdata.substr(0, pos);
                std::string password = userdata.substr(pos+1);
                User user(username, password);
                App::userList.push_back(user);
            }
        }
        file.close();
        App::app_homepage();
        if(App::exit) {
            file.open("users.csv");
            if(file.is_open()) {
                for(User user: App::userList) {
                    file << user.username << ',' << user.getPass() << '\n';
                }
            }
            file.close();
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "OOps... App Crashed Unexpectedly \n\nPress Enter to ReStart App!";
        std::cin.get();
        // std::cerr << e.what() << '\n';
    }
}
