#include <iostream>
#include <random>
#include <ctime>
#include <stack>

using namespace std;
#include "State.h"
int main(){
    srand(time(0));
    State a;
    a.createtable();
    a.printtable();
    return 0;
}