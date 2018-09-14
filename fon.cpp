#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end())
#define tr(c, it) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

int main()
{
    int n;
    cin >> n;
    string s;
    getline(cin,s); // rest of line
    getline(cin,s); // blank line
    fr(_, n) {
        vector< string > vs;
        while (getline(cin, s)) {
            if (s.empty() || cin.eof()) break;
            vs.insert(vs.end(), s);
        }
        int r = 0;
        tr(vs, it) {
            s = *it;
            fr(i, s.length()) {
                if (s.at(i) == '1'){
                    int x = 1, y = 1;
                    int a = i;
                    while(a < s.length() && s.at(a) == '1') {x++; a++;}
                    vector< string >::iterator b = it;
                    while(b != vs.end() && ((string)*b).at(i) == '1') {y++; b++;}
                    if ((x * y) > r) r = x*y;
                }   
            }
        }
        cout << r;
    }
    
}
/*
1

10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110

*/