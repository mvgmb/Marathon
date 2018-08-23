#include <iostream>
#include <math.h>
using namespace std;

int main () {
    string in;
    while (cin >> in) {
        int num = 0;
        for (int i = 0; i < in.length(); i++){
            if (in[i] <= 90) {
                num += in[i] - 64 + 26;
            }
            else {
                num += in[i] - 96;
            }
        }
        bool isPrime = true;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) isPrime = false;
        }
        if (isPrime || num == 1 || num == 2) {
            cout << "It is a prime word." << endl;
        }
        else {
            cout << "It is not a prime word." << endl;
        }
    }
}