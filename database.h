#pragma once

#include "fio.h"
//#include "profile.h"
#include "account.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>

class Database {
public:
    std::vector<Account*> accounts;
    int n;
    char* filename;

    Database() {
        char buffer[] = "accounts.txt";
        filename = (char*)std::malloc(sizeof(buffer));
        strcpy(filename, buffer);
        n = 0;
    }

    Database(char* filename){
        this -> filename = (char*)std::malloc(sizeof(filename));
        strcpy(this -> filename, filename);
        n = 0;
    }

    ~Database() {
        std::cout << "~Database\n";
        // accounts.clear();
        // std::free(filename);
    }


    // Profile create_profile() {
    //     Fio fio;
    //     fio.init_fio();
    //     Deposit deposit;
    //     deposit.init();
    // }

    void append(Account& account) {
        account.init();
        accounts.push_back(&account);
        n++;
    }


    void fio_search(Fio& necessary_fio) {
        int returned_values = 0;
        for (int i = 0; i < n; i++) {
            if (accounts[i] -> get_fio() == necessary_fio) { 
                std::cout << *accounts[i];
                returned_values++;
            }
        }
        if (!returned_values) {
            std::cout << "there are no profiles with this fio\n";
        }
    }


    void print_database() {
        for (int i = 0; i < n; i++) {
            std::cout << *accounts[i];
        }
    }

    void exit_program() {
        std::ofstream outfile(filename, std::ios::app); // Use std::ios::app flag for append mode
        if (outfile.is_open()) {
            for (int i = 0; i < n; i++) {
                outfile << *accounts[i];
            }
            outfile.close();
        }
        else {
            // File creation failed, try creating a new file
            outfile.open(filename);
            if (outfile.is_open()) {
                for (int i = 0; i < n; i++) {
                    outfile << *accounts[i];
                }
                outfile.close();
            }
            else {
                std::cout << "Unable to create or open file\n";
            }
        }
    }


    // void exit_program() { 
    //     std::ofstream outfile(filename);
    //     if (outfile.is_open()) {
    //         for (int i = 0; i < n; i++) {
    //             outfile << *accounts[i];
    //         }
    //         outfile.close();
    //     }   
    //     else {
    //         std::cout << "Unable to open file\n"; 
    //     }
    //     exit(0);
    // }
};