#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    
    int N = 0, K = 0, count = 0;
    list<int> arr;
    vector<int> value;
    list<int> :: iterator iter;

    cin >> N >> K;

    for(int i=0;i<N;i++){
        arr.push_back(i+1);
    }

    iter = arr.begin();

    while(!arr.empty()){
        for(int i=0;i<K-1;i++){
            iter++;
            if(iter == arr.end()){
                iter++;
            }
        }
        value.push_back(*iter);
        arr.erase(iter);
        iter++;
        if(iter == arr.end()){
            iter++;
        }
    }
    
    cout << "<";
    for(auto it : value){
        cout << it << ", ";
        
    }
    cout << ">" << endl;

    cout << "\n";


    
    return 0;
}
