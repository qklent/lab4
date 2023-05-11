#pragma once

#include "account.h"


class Credit: public Account{
private:
    int credit_card_number;
    double doubt;
    double interest_rate;
public:
    Credit(Fio fio, int credit_card_number, double doubt, double interest_rate): Account(fio){
        this -> credit_card_number = credit_card_number;
        this -> doubt = doubt;
        this -> interest_rate = interest_rate;
    }

    Credit(){
        this -> credit_card_number = -1;
        this -> doubt = -1;
        this -> interest_rate = 100;
    }

    Credit(const Credit& otherCredit): Account(otherCredit){
        this -> credit_card_number = otherCredit.credit_card_number;
        this -> doubt = otherCredit.doubt;
        this -> interest_rate = otherCredit.interest_rate;
    }

    int get_credit_card_number(){
        return this -> credit_card_number;
    }

    double get_doubt(){
        return this -> doubt;
    }

    double get_interest_rate(){
        return this -> interest_rate;
    }

    void init() override {
        fio.init_fio();
        std::cout << "enter credit card number: ";
        credit_card_number = cin_int();
        std::cout << "enter doubt: ";
        doubt = cin_double_only_positive();
        std::cout << "enter interest rate: ";
        interest_rate = cin_double_in_range(0.0, 100.0);
    }
    

    std::ostream& print(std::ostream& os) const override {
        // int credit_card_number = consumer.credit_card_number;
        // double doubt = consumer.doubt;
        // double interest_rate = consumer.interest_rate;
        os << "Credit: " << '\n';
        os << fio << "credit card number: " << credit_card_number << '\n' << "doubt: " << doubt << '\n' << "interest rate: " << interest_rate << "\n\n";
        return os;
    }

    Credit operator+(double sum_to_add){
        Credit new_credit = *this;
        new_credit.doubt += sum_to_add;
        return new_credit;
    } 

};

