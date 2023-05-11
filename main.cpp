#include "account.h"
#include "fio.h"
#include "safe_input.h"
#include "credit.h"
#include "deposit.h"
#include "database.h"
#include "utils.h"


//in utils create a normal choose function
//so that u can use whatever database u want
//and after using save func on 1 database program should not stop
//because we still haven't saved other database
//save function stopped working btw(doesn't write to the file)
//fio search also doesn't work! Hooray!
//'ve got memory leak in database fio search(n in for loop is large number)
//ошибка в том что я удаляю мапять в неиспользованной базе данных
int main() {
    start();
    // Deposit d;
    // Fio fio;
    // fio.init_fio();
    // int a = 2;
    // double b = 3;
    // database_deposit.append(d);
    // database_deposit.exit_program();
}