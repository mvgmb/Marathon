# Some Reminders

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