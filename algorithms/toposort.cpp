#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define vi vector< int >
#define vii vector< vi >

using namespace std;

int n, m;
int in[10000000];   
vi con[10000000];  

int main() {
    scanf("%d %d", &n, &m); 

    // works like a one way graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        con[u].push_back(v);
        in[v]++;
    }

    queue< int > q;
    // add every non conendent task to queue
    for(int i = 0; i< n; i++){
        if(in[i] == 0) {
            q.push(i);
            in[i]--;
        }
    }

    vi order;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u); 
        // simulate "u" completion
        // aka remove 1 conendency point from everyone "u" conendent
        for (int i = 0; i < con[u].size(); i++) {
            int v = con[u][i];
            in[v]--;
            if(in[v] == 0) { // if "u" was the only task remaining, add it to the queue
                q.push(v);
            }
        }
    }
    if(order.size() != n) printf("IMPOSSIBLE\n"); // some task wasn't possible
    else {
        for (int i = 0; i< order.size(); i++) {
            printf("%d ", order[i]+1);
        }
        printf("\n");
    }
} 