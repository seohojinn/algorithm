#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int arr[1000][10000];
int arr2[1000][10000];

int main() {
    
    int N=0,M=0,V=0;
    int vertex1=0,vertex2=0;
    stack<int> dfs;
    queue<int> bfs;
    vector<int> data;
    
    cin >> N >> M >> V;
    
    for(int i=0;i<M;i++){
        cin >> vertex1 >> vertex2;
        arr[vertex1-1][vertex2-1]=1;
        arr[vertex2-1][vertex1-1]=1;
        arr2[vertex1-1][vertex2-1]=1;
        arr2[vertex2-1][vertex1-1]=1;
    }
    
    dfs.push(V);
    data.push_back(V);
    for(int i=0;i<N;i++){
        arr[i][V-1]=0;
    }
    while(!dfs.empty()){
        for(int i=0;i<N;i++){
            if(arr[dfs.top()-1][i]==1){
                dfs.push(i+1);
                data.push_back(i+1);
                for(int j=0;j<N;j++){
                    arr[j][i]=0;
                }
                break;
            }
            else if(i==N-1){
                dfs.pop();
            }
        }
    }
    
    for(auto it : data){
        cout << it << " ";
    }
    cout << endl;
    
    data.clear();
    
    bfs.push(V);
    data.push_back(V);
    for(int i=0;i<N;i++){
        arr2[i][V-1]=0;
    }
   
    while(!bfs.empty()){
        for(int i=0;i<N;i++){
            if(arr2[bfs.front()-1][i]==1){
                bfs.push(i+1);
                data.push_back(i+1);
                for(int j=0;j<N;j++){
                    arr2[j][i]=0;
                }
            }
        }
        bfs.pop();
    }
    
    for(auto it : data){
        cout << it << " ";
    }
    cout << endl;
    
    
    return 0;
}

