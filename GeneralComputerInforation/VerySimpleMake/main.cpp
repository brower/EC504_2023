#include <cmath>
#include <iostream>
#include <cstdlib>
#include "factorial.h"
#include "hello.h"

using namespace std;

int main(){
    print_hello();
    cout << endl;
    cout << "The factorial of 6 is " << factorial(6) << endl;
    return 0;
}
