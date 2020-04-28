#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> Pair;

int search(int data, vector<int> idx_data,int N){
    int idx = 0;
    for(int i=0;i<N;i++){
        if(data == idx_data[i]){
            idx = i+1;
            break;
        }
    }
    return idx;
}

int main(){
    
    vector<Pair> arr;
    vector<int> idx_data ,idx_data2;
    int N = 0, data = 0, data2 = 0, max = 0, min = 0;
    int idx = 0;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> data;
        arr.push_back({data,0});
        idx_data.push_back(data);
    }
    for(int i=0;i<N;i++){
        cin >> data2;
        arr[i].second = data2;
        idx_data2.push_back(data2);
    }
    
    sort(arr.begin(),arr.end());
    
    for(auto it : arr){
        cout << it.first << " " << it.second << endl;
    }
    
    for(int i=N-1;i>0;i--){
        if(arr[i].second > arr[i-1].second){
            idx = search(arr[i].first,idx_data,N);
            for(int j=0;j<N;j++){
                if(arr[j].first != arr[i].first && arr[j].second == arr[i].second){
                    min = arr[j].first;
                    max = arr[j].first;
                    break;
                }
            }
            for(int j=N-1;j>0;j--){
                if(arr[j].second < arr[i].second && arr[j-1].second > arr[i].second){
                    min = arr[j-1].first + 1;
                    max = arr[j].first - 1;
                }
            }
            if(*max_element(idx_data2.begin(),idx_data2.end()) == arr[i].second){
                max = arr[0].first - 1;
            }
            
        }
        for(int j=0;j<N;j++){
            if(arr[j].first != arr[i].first && arr[j].second == arr[i].second){
                min = arr[j].first;
                max = arr[j].first;
                break;
            }
        }
    }
    
    cout << idx << endl;
    cout << min << " " << max << endl;
    
    return 0;
}
