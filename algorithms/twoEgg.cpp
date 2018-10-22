#include<bits/stdc++.h> 
using namespace std; 
  
int twoEggDrop(int k) { 
   return ceil((-1.0 + sqrt(1 + 8*k))/2.0); 
} 
  
int main() { 
    int loop; cin >> loop;
    int k;
    while(loop--){ 
        cin >> k;
        cout << twoEggDrop(k) << endl; 
    }
    return 0;  
} 