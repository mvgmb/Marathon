#include <iostream>
#include <string>
using namespace std;


int main() {
    string right[9] = {"one","two","three","four","five","six","seven","eight","nine"};
    int num;
    cin >> num;
    if (num<10) cout << right[num-1];
    else if (num == 10) cout << "ten";
    else if (num == 11) cout << "eleven";
    else if (num == 12) cout << "twelve";
    else if (num == 13) cout << "thirteen";
    else if (num == 14) cout << "fourteen";
    else if (num == 15) cout << "fifteen";
    else if (num == 16) cout << "eightteen";
    else if (num == 17) cout << "seventeen";
    else if (num == 18) cout << "eightteen";
    else if (num == 19) cout << "nineteen";
    else{
        string left[8] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
        cout << left[num/10-1] << "-" << right[num%10-1];
    }
}