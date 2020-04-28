#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> value;
vector<vector<int> > arr;
int front;
int check[1000];

void dfs(int V){
    value.push_back(V+1);
    check[V]=1;
    
    for(auto it : arr[V]){
        if(check[it]==0){
            dfs(it);
        }
    }
}

int main() {
    
    int N=0,M=0,V=0;
    int node_1=0,node_2=0;
    int check2[1000]={0,};
    queue<int> bfs;
    
    cin >> N >> M >> V;
    
    bfs.push(V-1);
    arr.resize(N);
    check2[V-1]=1;
    
    for(int i=0;i<M;i++){
        cin >> node_1 >> node_2;
        arr[node_1-1].push_back(node_2-1);
        arr[node_2-1].push_back(node_1-1);
    }
    
    for(int i=0;i<N;i++){
        sort(arr[i].begin(),arr[i].end());
    }
    
    dfs(V-1);
    
    for(auto it : value){
        cout << it << " ";
    }
    cout << endl;
    
    value.clear();
    
    value.push_back(V);

    while(!bfs.empty()){
        front = bfs.front();
        for(auto it : arr[front]){
            if(check2[it]==0){
                bfs.push(it);
                value.push_back(it+1);
                check2[it]=1;
            }
        }
        bfs.pop();
    }

    for(auto it : value){
        cout << it << " ";
    }
    cout << endl;

    
    return 0;
}
