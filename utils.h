#pragma once
#include "database.h"
#include "deposit.h"
#include "credit.h"
#include "fio.h"
#include <cstring>


int switch_tree(Database database, int func_num);
int choose_func(Database database);


void start() {
    char deposit_filename[] = "deposit.txt";
    char credit_filename[] = "credit.txt";
    Database database_credit(credit_filename);
    Database database_deposit(deposit_filename);
    std::cout << "choose database\n";
    std::cout << "1 - deposit\n" << "2 - credit\n";
    int database_num = cin_int_in_range(1, 2);
    int func_num;
    if (database_num == 1) { 
        while (true) {
            if (choose_func(&database_deposit) == 1) {
                break;
            }
        }
    }
    else {
        while (true) {
            if (choose_func(&database_credit) == 1) {
                break;
            }
        }
    }
}


int choose_func(Database* database) {
    std::cout << "choose function\n";
    std::cout << "1 - add element\n2 - fio search\n3 - exit\n";
    int func_num = cin_int_in_range(1, 3);
    return switch_tree(database, func_num);
}


int switch_tree(Database* database, int func_num) {
    if (func_num == 1) {
        if (!strcmp(database -> filename, "deposit.txt")) {
            Deposit profile;// = new Deposit()
            database -> append(profile);
        }
        else {
            Credit profile;
            database -> append(profile);
        }
    }   
    else {
        if (func_num == 2){
            std::cout << "enter the fio that you want to find\n";
            Fio fio;
            fio.init_fio();
            database -> fio_search(fio);
        }
        else {
            database -> exit_program();
            return 1;
        }
    }
    return 0;
}  