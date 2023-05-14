#include "account.h"
#include "fio.h"
#include "safe_input.h"
#include "credit.h"
#include "deposit.h"
#include "database.h"
#include "utils.h"







int main() {
    start();
    //database destructor(objects doesn't call destructor)
    // char buffer[] = "deposit.txt";
    // char* deposit_filename = (char*)std::malloc(strlen(buffer + 1));
    // strcpy(deposit_filename, buffer);
    // // char buffer2[] = "credit.txt";
    // // char* credit_filename = (char*)std::malloc(strlen(buffer2) + 1);
    // // strcpy(credit_filename, buffer2);
    // // Database database_credit(credit_filename);
    // // Database database_deposit(deposit_filename);
    // std::cout << strcmp(deposit_filename, "deposit.txt");
}
