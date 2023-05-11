#pragma once

#include "deposit.h"
#include "credit.h"

class Profile: public Account {
public:
    Deposit* deposit;
    Credit* credit;

    Profile(Deposit deposit, Credit credit){
        this -> deposit = &deposit;
        this -> credit = &credit;
    }

    Profile(const Profile& othrerProfile) {
        this -> deposit = othrerProfile.deposit;
        this -> credit = othrerProfile.credit;
    }

    void init_profile() {
        deposit -> init_deposit();
        credit -> init_account();
        fio.init_fio();
    }

    friend std::ostream& operator<<(std::ostream& os, const Profile& profile) {
        os << profile.deposit -> get_fio() << '\n';
        os << *(profile.deposit) << std::endl << std::endl;
        os << *(profile.credit) << std::endl;
        return os;
    }

};
