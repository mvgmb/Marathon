# Some Reminders

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

//Another note to keep in mind: When a token from the left-hand side of #define appears in the
//right-hand side, it should be placed in braces to avoid many nontrivial problems.
```

### Vectors

```c++
    vector < int > N;
    vector < vector< int > > CorrectDefinition;
    vector< int > v(10);
    v[i] = 2;

    v.size();
    v.empty();
    v.push_back(3);
    v.resize(25);
    vector< string > names(20, “Unknown”);
    
    int N, M;
    vector< vector< int > > Matrix(N, vector< int >(M, -1));
    
    // Copies vector and uses in function
    void some_function(vector< int > v) { /* Do stuff */ }
    
    // Does not copy or change vector
    void some_function(const vector< int >& v) { /* Do stuff */ }
    
    // Does not copy vector, but may change it
    void some_function(vector< int >& v) { /* Do stuff */ }
```

### Pairs

```c++
template< typename T1, typename T2 > struct pair {
T1 first;
T2 second;
};

pair<string, pair< int,int > > P;
string s = P.first; // extract string
int x = P.second.first; // extract first int
int y = P.second.second; // extract second int
```
For example, if you want to sort the array of integer points so that they form a polygon, it’s a good idea to put them to the vector< pair<double, pair<int,int> >, where each element of vector is { polar angle, { x, y } }. One call to the STL sorting function will give you the desired order of points.

### Iterators

STL algorithms always use two iterators, called “begin” and “end.” 
The end iterator is pointing _not to the last object_, however, but to the **first invalid object**, or the object directly following the last one. It’s often very convenient.

Each STL container has member functions **begin()** and **end()** that return the begin and end iterators for that container.

Based on these principles, **c.begin() == c.end() if and only if c is empty**, and **c.end() – c.begin() will always be equal to c.size()**. (*The last sentence is valid in cases when iterators can be subtracted, i.e. begin() and end() return random access iterators, which is not true for all kinds of containers. See the prior example of the double-linked list.*)

The STL-compliant reverse function should be written as follows:
```c++
template< typename T > void reverse_array_stl_compliant(T *begin, T *end) {
    // We should at first decrement 'end'
    // But only for non-empty range
    if(begin != end) {
        end--;
        if(begin != end) {
            while(true) {
            **swap(*begin, *end);**
            begin++;
            if(begin == end) {
                break;
            }   
            end--;
            if(begin == end) {
                break;
            }
            }
        }
    }
}
```
Note that this function does the same thing as the **standard function std::reverse(T begin, T end)** that can be found in algorithms module (#include ).

In addition, any object with enough functionality can be passed as an iterator to STL algorithms and functions. That is where the power of templates comes in! See the following examples:

```c+
vector< int > v;
// ...
vector< int > v2(v);
vector< int > v3(v.begin(), v.end()); // v3 equals to v2
```

It creates the vector v2 that is equal to the first half of vector v.

```c++
vector< int > v;
// ...
vector< int > v2(v.begin(), v.begin() + (v.size()/2));
```

Here is an example of **reverse()** function:

```c++
int data[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
reverse(data+2, data+6); // the range { 5, 7, 9, 11 } is now { 11, 9, 7, 5 };
```

Each container also has the **rbegin()** and **rend()** functions, which return **reverse iterators**. Reverse iterators are used to traverse the container in backward order. Thus this will create v2 with first half of v, ordered back-to-front.

```c++
vector< int > v;
vector< int > v2(v.rbegin()+(v.size()/2), v.rend());
```
To **create an iterator object**, we must specify its type. The type of iterator can be constructed by a type of container by appending “::iterator”, “::const_iterator”, “::reverse_iterator” or “::const_reverse_iterator” to it. Thus, vector can be traversed in the following way:

```c++
vector< int > v; 
// ... 
// Traverse all container, from begin() to end()
for(vector< int >::iterator it = v.begin(); it != v.end(); it++) {
    *it++; // Increment the value iterator is pointing to
}
```

*I recommend you use ‘!=’ instead of ‘<’, and ‘empty()’ instead of ‘size() != 0′ — for some container types, it’s just very inefficient to determine which of the iterators precedes another.*

The **find()** algorithm looks for appropriate elements in an interval. 
If the element is found, the iterator pointing to the *first occurrence of the element is returned*. 
Otherwise, the return value equals the end of interval.

**To get the index of element found**, one should subtract the beginning iterator from the result of find():

```c++
int i = (find(v.begin(), v.end(), 49) - v.begin();
if(i < v.size()) {
// ...
}
```

The **min_element** and **max_element** algorithms return an iterator to the respective element. To get the value of min/max element, like in *find()*, use *min_element(…) or *max_element(…), to get index in array subtract the begin iterator of a container or range:

```c++
int data[5] = { 1, 5, 2, 4, 3 };
vector< int > X(data, data+5);
int v1 = *max_element(X.begin(), X.end()); // Returns value of max element in **VECTOR**
int i1 = *min_element(X.begin(), X.end()) – X.begin; // Returns value of min element in **VECTOR**

int v2 = *max_element(data, data+5); // Returns value of max element in **ARRAY**
int i3 = *min_element(data, data+5) – data; // Returns value of min element in **ARRAY**
```

Now you may see that the useful macros would be:

```c++
#define all(c) c.begin(), c.end()
```
*Don’t put the whole right-hand side of these macros into parentheses – **that would be wrong!***

Another good algorithm is **sort()**. It’s very easy to use. Consider the following examples:
```c++
vector< int > X; 
// ... 
sort(X.begin(), X.end()); // Sort array in ascending order
sort(all(X)); // Sort array in ascending order, use our #define
sort(X.rbegin(), X.rend()); // Sort array in descending order using with reverse iterators
```

### Compiling STL Programs

One of STL’s habits is **unreadable error messages**.
```c++
vector< int >::iterator it = v.begin(); // INcorrect
vector< int >::const_iterator it = v.begin(); // correct
```
In spite of this, let me tell about very important feature of GNU C++ called ‘typeof’. This operator is replaced to the type of an expression during the compilation.
```c++
typeof(a+b) x = (a+b);
```

Cool example:

```c++
// Traverse (any) container
#define tr(container, it) \ 
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
```

By using these macros **we can traverse every kind of container**, not only vector.

```c++
void f(const vector< int >& v) {
    int r = 0;
    tr(v, it) {
        r += (it)(*it);
    }
    return r;
}
```

Traversing macros is not really necessary for vectors, but **it’s very convenient for more complex data types**, where indexing is not supported and iterators are the only way to access data. We will speak about this later in this article.

### Data manipulation in vector

One can insert an element to vector by using the **insert() function**:

```c++ 
vector< int > v;
// ...
v.insert(1, 42); // Insert value 42 after the first

vector< int > v2;
v.insert(1, all(v2));
// Shift all elements from second to last to the appropriate number of elements.
// Then copy the contents of v2 into v.
```

Vector also has a member **function erase**, which has two forms. Guess what they are:

```c++ 
erase(iterator);
erase(begin iterator, end iterator);
```

### String
There is a **special container** to manipulate with strings. The string container has a *few differences* from vector< char >. Most of the differences come down to string manipulation functions and memory management policy.

String has a substring function **without iterators**, just indices:
```c++
string s = "hello";
s1 = s.substr(0, 3), // "hel"
s2 = s.substr(1, 3), // "ell"
s3 = s.substr(0, s.length()-1), "hell"
s4 = s.substr(1); // "ello"
```
Beware of (s.length()-1) on empty string because s.length() is unsigned and **unsigned(0) – 1 is definitely not what you are expecting!**

### Set

Consider we need a container with the following features:
- add an element, but do not allow duples [duplicates?]
- remove elements
- get count of elements (distinct elements)
- check whether elements are present in set

This is quite a frequently used task. STL provides the special container for it – set. Set can add, remove and check the presence of particular element in O(log N), where N is the count of objects in the set. While adding elements to set, the duples [duplicates?] are discarded. A count of the elements in the set, N, is returned in O(1). We will speak of the algorithmic implementation of set and map later — for now, let’s investigate its interface:

```c++
set< int > s;

for(int i = 1; i <= 100; i++) {
    s.insert(i); // Insert 100 elements, [1..100]
}

s.insert(42); // does nothing, 42 already exists in set

for(int i = 2; i <= 100; i += 2) {
    s.erase(i); // Erase even values
}

int n = int(s.size()); // n will be 50
```

The **push_back()** member **may not** be used with set. It make sense: *since the order of elements in set does not matter*, push_back() is not applicable here.

Since **set is not a linear container**, it’s impossible to take the element in set by index. Therefore, **the only way to traverse the elements of set is to use iterators**.

```c++
// Calculate the sum of elements in set
set< int > S;
// ...
int r = 0;
for(set< int >::const_iterator it = S.begin(); it != S.end(); it++) {
    r += *it;
}
```
It’s more elegant to use *traversing macros here*. Why? Imagine you have a set< pair<string, pair< int, vector< int > > >. How to traverse it? Write down the iterator type name? Oh, no. **Use our traverse macros instead.**
```c++
set< pair< string, pair< int, vector< int > > > SS;
int total = 0;
tr(SS, it) {
    total += it->second.first;
}
```
Notice the ‘*it->second.first*’ syntax. Since ‘*it*’ is an iterator, we need to take an object from ‘*it*’ before operating. So, the correct syntax would be ‘*(*it).second.first*’. However, it’s easier to write ‘**something->’ than ‘(*something)**’. The full explanation will be quite long –just remember that, for iterators, **both syntaxes are allowed**.    


**To determine whether some element is present in set use ‘find()’ member function.** Don’t be confused, though: there are several ‘find()’ ’s in STL. **There is a global algorithm ‘find()’, which takes two iterators, element, and works for O(N)**. It is possible to use it for searching for element in set, **but why use an O(N) algorithm while there exists an O(log N) one?** *While searching in set and map (and also in multiset/multimap, hash_map/hash_set, etc.)* **do not use global find** – **instead, use member function ‘set::find()’**. *As ‘ordinal’ find, set::find will return an iterator, either to the element found, or to ‘end()’*. So, the element presence check looks like this:
```c++
set< int > s;
// ...
if(s.find(42) != s.end()) {
    // 42 presents in set
}
else {
    // 42 not presents in set
}
```

**Another algorithm that works for O(log N) while called as member function is count.** Some people think that:

```c++
if(s.count(42) != 0) {
    // …
}
```

Or even

```c++
if(s.count(42)) {
    // …
}
```

*is easier to write*. Personally, I don’t think so. **Using count() in set/map is nonsense: the element either presents or not.** As for me, I prefer to use the following two macros:
```c++
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
```
(**Remember that all(c) stands for “c.begin(), c.end()”**)

Here, ‘**present()**’ *returns whether the element presents in the container with member function ‘find()’* (i.e. set/map, etc.) while ‘**cpresent**’ *is for vector*.

**To erase an element from set use the erase() function.**
```c++
set< int > s;
// …
s.insert(54);
s.erase(29);
```
The erase() function also has the **interval form**:
```c++
set< int > s;
// ...

set< int >::iterator it1, it2;
it1 = s.find(10);
it2 = s.find(100);
// Will work if it1 and it2 are valid iterators, i.e. values 10 and 100 present in set.

s.erase(it1, it2); // Note that 10 will be deleted, but 100 will remain in the container
```
Set has an interval constructor:
```c++
int data[5] = { 5, 1, 4, 2, 3 };
set< int > S(data, data+5);
```
**It gives us a simple way to get rid of duplicates in vector, and sort it:**
```c++
vector< int > v;
// …
set< int > s(all(v)); // Remember that all(v) stands for "v.begin(), v.end"
vector< int > v2(all(s));
```
**Here ‘v2′ will contain the same elements as ‘v’ but sorted in ascending order and with duplicates removed.**

*Any comparable elements can be stored in set.*

### Map
There are two explanation of map. The simple explanation is the following:
```c++
map< string, int > M;
M["Top"] = 1;
M["Coder"] = 2;
M["SRM"] = 10;

int x = M["Top"] + M["Coder"];

if(M.find("SRM") != M.end()) {
    M.erase(M.find("SRM")); // or even M.erase("SRM")
}
```
Very simple, isn’t it?

**Actually map is very much like set, except it contains not just values but pairs <key, value>.** *Map ensures that at most one pair with specific key exists.* Another quite pleasant thing is that **map has operator [] defined**.

Traversing map is easy with our ‘tr()’ macros. **Notice that iterator will be an std::pair of key and value**. So, *to get the value use it->second*. The example follows:

```c++
map< string, int > M;
// …
int r = 0;
tr(M, it) {
    r += it->second;
}
```

**Don’t change the key of map element by iterator, because it may break the integrity of map internal data structure** (see below).

**There is one important difference between map::find() and map::operator [].** While **map::find() will never change the contents of map**, **operator [] will create an element if it does not exist**. In some cases this could be very convenient, but it’s definitly a bad idea to use operator [] many times in a loop, when you do not want to add new elements. **That’s why operator [] may not be used if map is passed as a const reference parameter to some function**:
```c++
void f(const map< string, int >& M) {
    if(M["the meaning"] == 42) { // Error! Cannot use [] on const map objects!
    }
    if(M.find("the meaning") != M.end() && M.find("the meaning")->second == 42) { // Correct
        cout << "Don't Panic!" << endl;
    }
}
```
#### Notice on Map and Set

**Internally map and set are almost always stored as red-black trees**. We do not need to worry about the internal structure, the thing to remember is that the elements of map and set are always sorted in ascending order while traversing these containers. **And that’s why it’s strongly not recommended to change the key value while traversing map or set**: If you make the modification that breaks the order, it will lead to improper functionality of container’s algorithms, at least.

But the fact that **the elements of map and set are always ordered** can be practically used while solving TopCoder problems.

**Another important thing is that operators ++ and -- are defined on iterators in map and set.** Thus, if the value 42 presents in set, and it’s not the first and the last one, than the following code will work:
```c++
set< int > S;
// ...
set< int >::iterator it = S.find(42);
set< int >::iterator it1 = it, it2 = it;
it1--;
it2++;
int a = *it1, b = *it2;
```
Here ‘a’ will contain the first neighbor of 42 to the left and ‘b’ the first one to the right.

### More on algorithms
Most algorithms are declared in the #include < algorithm > standard header. 
At first, STL provides three very simple algorithms: **min(a,b), max(a,b), swap(a,b)**.

The call to **sort(begin, end)** sorts an interval in ascending order. *Notice that sort() requires random access iterators, so it will not work on all containers*.

The call to **find(begin, end, element)** returns the iterator where ‘element’ first occurs, or **end if the element is not found**. 

The call to **count(begin, end, element) returns the number of occurrences of an element in a container or a part of a container**. 

Remember that **set and map have the member functions find() and count(), which works in O(log N)**, while **std::find() and std::count() take O(N).**

Other useful algorithms are **next_permutation()** and **prev_permutation()**. 

The call to next_permutation(begin, end) makes the interval [begin, end] hold the next permutation of the same elements, or **returns false if the current permutation is the last one.** Accordingly, next_permutation makes many tasks quite easy. If you want to check all permutations, just write:

```c++
vector< int > v;

for(int i = 0; i < 10; i++) {
    v.push_back(i);
}

do {
Solve(..., v);
} while(next_permutation(all(v));
```

**Don’t forget to ensure that the elements in a container are sorted before your first call to next_permutation(…)**. Their initial state should form the very first permutation; otherwise, some permutations will not be checked.

### String Streams

**You often need to do some string processing/input/output**. C++ provides two interesting objects for it: ‘**istringstream**’ and ‘**ostringstream**’. They are both declared in #**include < sstream >**.

Object **istringstream** allows you to read from a string like you do from a standard input. It’s better to view source:

```c++
void f(const string& s) { 

// Construct an object to parse strings
istringstream is(s); 

// Vector to store data
vector< int > v; 

// Read integer while possible and add it to the vector
int tmp;
while(is >> tmp) {
    v.push_back(tmp);
}
}
```

The **ostringstream** object is used to do formatting output. Here is the code:

```c++
string f(const vector< int >& v) {
// Constuct an object to do formatted output
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

return s;
```

### Creating Vector from Map

As you already know, map actually contains pairs of element. So you can write it in like this:
```c++
 map< string, int > M;
// ...
vector< pair< string, int > > V(all(M)); // remember all(c) stands for
(c).begin(),(c).end()
```
Now vector will contain the same elements as map. Of course, vector will be sorted, as is map. **This feature may be useful if you are not planning to change elements in map any more but want to use indices of elements in a way that is impossible in map**

### Copying data between containers

**Let’s take a look at the copy(…) algorithm.**
```c++ 
copy(from_begin, from_end, to_begin);
```

**This algorithm copies elements from the first interval to the second one**. The second interval 
should have enough space available. See the following code:

```c++
vector< int > v1;
vector< int > v2; 

// ... 

// Now copy v2 to the end of v1
v1.resize(v1.size() + v2.size());
// Ensure v1 have enough space
copy(all(v2), v1.end() - v2.size());
// Copy v2 elements right after v1 ones
```

**Another good feature to use in conjunction with copy is inserters**. I will not describe it here due to limited space but look at the code:

```c++
vector< int > v;
// ...
set< int > s;
// add some elements to set
copy(all(v), inserter(s));

The last line means:

tr(v, it) {
    // remember traversing macros from Part I
    s.insert(*it);
}
```

To insert elemements to vector with **push_back use back_inserter, or front_inserter** is available for deque container. And in some cases it is **useful to remember that the first two arguments for ‘copy’ may be** not only **begin/end**, but also **rbegin/rend, which copy data in reverse order.**

### Merging lists
Another common task is to operate with sorted lists of elements. Imagine you have two lists of elements — A and B, both ordered. You want to get a new list from these two. There are four common operations here:

- ‘union’ the lists, R = A+B
- intersect the lists, R = A*B
- set difference, R = A*(~B) or R = A-B
- set symmetric difference, R = A XOR B

STL provides four algorithms for these tasks: **set_union(…), set_intersection(…), set_difference(…) and set_symmetric_difference(…)**. They all have the same calling conventions, so let’s look at set_intersection.
```c++
end_result = set_intersection(begin1, end1, begin2, end2, begin_result);
```

**Here [begin1,end1] and [begin2,end2] are the input lists**. **The 'begin_result' is the iterator from where the result will be written**. But the size of the result is unknown, so this function **returns the end iterator** of output (which determines how many elements are in the result). See the example for usage details:

```c++
int data1[] = { 1, 2, 5, 6, 8, 9, 10 };
int data2[] = { 0, 2, 3, 4, 7, 8, 10 };

vector< int > v1(data1, data1+sizeof(data1)/sizeof(data1[0]));
vector< int > v2(data2, data2+sizeof(data2)/sizeof(data2[0]));

vector< int > tmp(max(v1.size(), v2.size());

vector< int > res = vector< int > (tmp.begin(), set_intersection(all(v1), all(v2), tmp.begin());
```

Look at the last line. We construct a new vector named 'res'. It is constructed via interval constructor, and the beginning of the interval will be the beginning of tmp. The end of the interval is the result of the set_intersection algorithm. This algorithm will intersect v1 and v2 and write the result to the output iterator, starting from 'tmp.begin()'. Its return value will actually be the end of the interval that forms the resulting dataset.

One comment that might help you understand it better: If you would like to just get the number of elements in set intersection, use int cnt = set_intersection(all(v1), all(v2), tmp.begin()) – tmp.begin();

Actually, I would never use a construction like ' vector< int > tmp'. I don't think it's a good idea to allocate memory for each set_*** algorithm invoking. Instead, I define the global or static variable of appropriate type and enough size. See below:

```c++
set< int > s1, s2;
for(int i = 0; i < 500; i++) {
s1.insert(i*(i+1) % 1000);
s2.insert(iii % 1000);
} 

static int temp[5000]; // greater than we need 

vector< int > res = vi(temp, set_symmetric_difference(all(s1), all(s2), temp));
int cnt = set_symmetric_difference(all(s1), all(s2), temp) – temp;
```

Here 'res' will contain the symmetric difference of the input datasets.

Remember, input datasets need to be sorted to use these algorithms. So, another important thing to remember is that, because sets are always ordered, we can use set-s (and even map-s, if you are not scared by pairs) as parameters for these algorithms.

**These algorithms work in single pass, in O(N1+N2), when N1 and N2 are sizes of input datasets.**
