#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <chrono>
#include <random>
using namespace std;

//mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end())
#define pb push_back
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) ((c).find(all(c),x) != (c).end())

typedef vector< int > vi;
typedef vector< vi > vii;
typedef pair< int, int > ii;

int main()
{   
    auto start = std::chrono::steady_clock::now();

    pair< string,int > p;
    p = {"boii",321};
    cout << p.first << " " << p.second;

    auto finish = std::chrono::steady_clock::now();
    double elapsed_seconds = std::chrono::duration_cast< std::chrono::duration<double> >(finish - start).count();
    cout << endl << elapsed_seconds;
}