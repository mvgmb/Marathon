#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main() {
    vector< int > v (1, 2);
    int data[5] = { 2, 5, 2, 4, 190 };
    v.pb(3);
    cout << "vector ";
    int a = 100;
    vector< int >::iterator it = v.begin();
    cout << *it << endl;
    it++;
    cout << *max_element(all(v)) << endl;
     
    cout << *max_element(data, data+5) << endl;
    // Traverse the vector using const_iterator
    for(vector< int >::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it;
    }
    cout << endl;

    set<int> s;
    s.insert(1);
    s.insert(1); // duplicate
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.erase(2);
    cout << "set ";
    tr(s, i) {
        cout << *i;    
    }
    cout << endl;
    if (s.find(3) != s.end()) { // returns 3 iterator (true) or end iterator (false)
        cout << "found 3!";
    }
    cout << endl;



    return 0;
}
