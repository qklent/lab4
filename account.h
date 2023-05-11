#pragma once

#include "fio.h"


class Account{
protected:
    Fio fio;
    static int count;
public:
    Account(){
        Fio fio;
        this -> fio = fio;
    }

    Account(Fio fio){
        this -> fio = fio;
    }

    Account(const Account& otherAccount) {
        this -> fio = otherAccount.fio;
    }


    Fio get_fio() {
        return fio;
    }

    virtual void init() {
        fio.init_fio();
    }


    virtual std::ostream& print(std::ostream& os) const {
        os << fio;
        return os;
    }


    friend std::ostream& operator<<(std::ostream& os, const Account& obj) {
        return obj.print(os);
    }
};
