#pragma once

#include "fio.h"
#include "safe_input.h"
#include "account.h"



class Deposit: public Account {
private:
    int account_number;
    double balance;
public:
    Deposit(Fio fio, int account_number, double balance): Account(fio) {
        this -> account_number = account_number;
        this -> balance = balance;
    }

    Deposit() {
        this -> account_number = -1;
        this -> balance = -1;
    }

    Deposit(const Deposit& otherDeposit): Account(otherDeposit.fio) {
        this -> account_number = otherDeposit.account_number;
        this -> balance = otherDeposit.balance;
    }


    int get_account_number(){
        return this -> account_number;
    }

    double get_balance(){
        return this -> balance;
    }

    void init() override {
        fio.init_fio();
        std::cout << "enter account number: ";
        account_number = cin_int();
        std::cout << "enter balance: ";
        balance = cin_double();
    }

    std::ostream& print(std::ostream& os) const override {
        // int acc_num = consumer.account_number;
        // double balance = consumer.balance;
        os << "Deposit: " << '\n';
        os << fio << "account number: " << account_number << '\n' << "balance: " << balance << "\n\n";
        return os;
    }

    Deposit operator+(double sum_to_add){
        Deposit new_deposit = *this;
        new_deposit.balance += sum_to_add;
        return new_deposit;
    }
};
