# Reminders

#### Template list
```c++
#include<bits/stdc++.h>
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

std::cout << setprecision(3) << 2.71828; // prints 2.71
std::cout << setbase(16) << 32; // prints 20

string s = "3";
int a = std::stoi(s);
a++;
cout << a; // a == 4

tolower(string);

getline(cin, string);

//Another note to keep in mind: When a token from the left-hand side of #define appears in the
//right-hand side, it should be placed in braces to avoid many nontrivial problems.
```
```c++
static int temp[5000]; // global static tmp, so we don't lose time allocation memory

min(a,b);
max(a,b);
swap(a,b);
sort(begin, end);
find(begin, en, element); // returns end if element is not found
count(begin, end, element);
// remember that set and map hava its own find and count (which takes O(log n))
do {
Solve(..., v);
} while(next_permutation(v.begin(), v.end());
// prev_permutation(begin, end);
```
```c++
istringstream is(s); 
// Vector to store data
vector< int > v; 
// Read integer while possible and add it to the vector
int tmp;
while(is >> tmp) {
    v.push_back(tmp);
}

ostringstream os; 
// Copy all elements from vector< int > to string stream as text
tr(v, it) {
    os << ' ' << *it;
}
// Get string from string stream
string s = os.str(); 
// Remove first space character
if(!s.empty()) { // Beware of empty string here
    s = s.substr(1);
} 

while (getline(std::cin, input1))
{
    if (input1.empty())
        break;
    username =input1;
    std::cout << input1 << std::endl << "Enter Input : ";
}
```
```c++
// set_union(…), set_intersection(…), set_difference(…) and set_symmetric_difference(…)
// end_result_iterator = set_intersection(begin1, end1, begin2, end2, begin_result);
set< int > s1, s2;
// ...
static int temp[5000];
vector< int > result(temp, set_symmetric_difference(all(s1), all(s2), temp));
int count = set_symmetric_difference(all(s1), all(s2), temp) - temp;
// 
```


#### Vectors
```c++
vector< int > v;
v.push_back(2);
boolean b = v.empty();
int var = v.size();
var = v[1];

v.insert(1,42) // Insert value 42 after the first
vector< int > v2;
v.insert(1, all(v2)); 
// Shift all elements from second to last to the appropriate number of elements.
// Then copy the contents of v2 into v.

erase(it);
erase(begin it, end it);

map< string, int > M;
vector< pair< string, int > > V(all(M)); // Creating vector from map

vector< int > v1;
vector< int > v2; 

v1.resize(v1.size() + v2.size());
copy(all(v2), v1.end() - v2.size());

int data1[] = { 1, 2, 5, 6, 8, 9, 10 };
vector< int > v1(data1, data1+sizeof(data1)/sizeof(data1[0]));

```

#### String 
```c++
string s = "hello";
s1 = s.substr(0, 3), // "hel"
s2 = s.substr(1, 3), // "ell"
s3 = s.substr(0, s.length()-1), "hell"
s4 = s.substr(1); // "ello"
// Beware of (s.length()-1) on empty string
```

#### Pairs
```c++
pair<string, pair< int,int > > P;
string s = P.first; // extract string
int x = P.second.first; // extract first int
int y = P.second.second; // extract second int
```
#### Iterators 
```c++
//something->’ and ‘(*something).’ are both allowed
// c == container
c.begin();
c.end();
c.rbegin(); // reversed begin
c.rend(); // reversed end
typeof(c)::iterator it;
typeof(c)::const_iterator it;
typeof(c)::reverse_iterator it;
typeof(c)::const_reverse_iterator it;
for(vector< int >::iterator it = v.begin(); it != v.end(); it++) {
    // value == *it
}

int data[5] = { 1, 5, 2, 4, 3 };
vector< int > X(data, data+5);
int v1 = *max_element(X.begin(), X.end()); // Returns value of max element in VECTOR

int i3 = *min_element(data, data+5) – data; // Returns value of min element in ARRAY

std::set<int>::iterator it = s.begin();
std::advance(it, s.size() / 2);
```

#### Set
```c++
// The only way to traverse the elements of set is to use iterators
set< int > s;
s.insert(1);
s.size();
s.erase(1);
s.find(42) != s.end()
// count() is useless
int data[5] = { 5, 1, 4, 2, 3 };
set< int > S(data, data+5); // Interval constructor
// Operators ++ and -- are defined on iterators in map and set
it++; it--;
```

#### Map 
```c++
map< string, int > M;
M["Top"] = 1;
M["Coder"] = 2;
M["SRM"] = 10;

int x = M["Top"] + M["Coder"];

if(M.find("SRM") != M.end()) {
    M.erase(M.find("SRM")); // or even M.erase("SRM");
}

int r = 0;
tr(M, it) {
    r += it->second;
}
// map::find() will never change the contents of map
// Operator [] will create an element if it does not exist
```
