#pragma once

#include <iostream>
#include <limits>
#include <string>

int cin_int() {
    int a;
    std::cin >> a;
    while(std::cin.fail()){
        std::cout << "enter int" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> a;
    }
    std::string buffer;
    std::getline(std::cin, buffer, '\n');
    return a;
}

double cin_double() {
    double a;
    std::cin >> a;
    while(std::cin.fail()){
        std::cout << "enter double" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> a;
    }
    std::string buffer;
    std::getline(std::cin, buffer, '\n');
    return a;
}

std::string cin_string(){
    std::string a;
    std::cin >> a;
    std::string buffer;
    std::getline(std::cin, buffer, '\n');
    return a;
}


std::string cin_string_symbol_only(){
    bool contains_digits = true;
    std::string str;
    while (contains_digits){
        str = cin_string();
        contains_digits = false;
        for (char c : str) {
            if (!std::isalnum(c) || isdigit(c)) {
                contains_digits = true;
                std::cout << "symbols only" << std::endl;
                break;
            }
        }
    }
    return str;
}

int cin_int_only_positive(){
    int a = cin_int();
    while (a < 0){
        std::cout << "int only positive" << std::endl;
        a = cin_int();
    }
    return a;
}

int cin_double_only_positive(){
    int a = cin_double();
    while (a < 0){
        std::cout << "double only positive" << std::endl;
        a = cin_double();
    }
    return a;
}


int cin_int_in_range(int left, int right){
    int a = cin_int();
    while (!(left <= a & a <= right)){
        printf("enter int number from %d to %d\n", left, right);
        a = cin_int();
    }
    return a;   
}

int cin_double_in_range(double left, double right){
    double a = cin_double();
    while (!(left <= a & a <= right)){
        printf("enter int number from %lf to %lf\n", left, right);
        a = cin_double();
    }
    return a;   
}