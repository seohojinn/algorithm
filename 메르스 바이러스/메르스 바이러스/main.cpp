#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;
typedef pair<int,int> Pair;

int main(){
    
    vector<Pair> arr, arr2;
    vector<int> idx;
    int min = INT_MAX, min_idx = 0;
    int N = 0, M = 0, data1 = 0, data2 = 0, count = 0;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> data1 >> data2;
        arr.push_back({data1,data2});
    }
    
    for(int i=0;i<M;i++){
        cin >> data1 >> data2;
        arr2.push_back({data1,data2});
    }
    
    for(int i=0;i<M;i++){
        do{
            min = INT_MAX;
            min_idx = 0;
            idx.clear();
            for(int j=0;j<N;j++){
                if(arr[j].first != 0 && arr2[i].second != 0 && arr[j].first <= arr2[i].first && arr[j].second >= arr2[i].first){
                    idx.push_back(j);
                }
            }
            if(!idx.empty()){
                for(auto it : idx){
                    if(min > arr[it].second - arr[it].first){
                        min = arr[it].second - arr[it].first;
                        min_idx = it;
                    }
                }
                arr[min_idx].first = 0;
                arr2[i].second -= 1;
                count += 1;
            }
        }while(!idx.empty());
        
    }
    
    cout << count << endl;
    
    return 0;
}
