#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include "util.h"

using std::cout, std::cin, std::string, std::endl;

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

class App {
public:
    static User currentUser;
    static std::vector<User> userList;
    static bool exit;

    static void app_homepage(){
        system("clear");
        exit = false;
        int choice = 0;
        cout << "Welcome !!!\n";
        cout << "1. Login \n2. SignUp \n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                login();
                break;
            case 2:
                signin();
                break;
            case 3:
                exit = true;
                system("clear");
                break;            
            default:
                cout << "Invalid Choice\nPress Enter to reEnter!";
                cin.get();
                cin.get();
                app_homepage();
                break;
        }
    }

    static void login(){
        system("clear");
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter you password: ";
        cin >> password;
        for(User user : userList) {
            if(user.username == username && user.getPass() == password) {
                currentUser = user;
                break;
            }
        }
        if(currentUser.username == username) {
            cout << "Hello " << currentUser.username << '\n';
            cout << "User successfully logged in!" << endl;
        } else {
            cout << "User not found!" << endl;
        }
        cout << "press Enter to go back to main menu" << endl;
        cin.get();
        cin.get();
        app_homepage();
    }

    static void signin() {
        system("clear");
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        User newUser(username, password);
        userList.push_back(newUser);
        cout << "press Enter to go back to main menu " << endl;
        cin.get();
        cin.get();
        app_homepage();
    }
};

bool App::exit = false;
User dummy;
User App::currentUser = dummy;
std::vector<User> userlist;
std::vector<User> App::userList = userlist;

#endif