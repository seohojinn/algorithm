#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int N = 0, data = 0, size = 0;
    vector<int> arr;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> data;
        arr.push_back(data);
        
        size = int(arr.size());
        
        sort(arr.begin(),arr.end(),less<>());
//        for(auto it : arr){
//            cout << it << " ";
//        }
//        cout << endl;
        
        if(size == 1){
            cout << arr[0] << "\n";
        }
        
        else if(size % 2 == 1){
            cout << arr[size/2] << "\n";
        }
        else{
            cout << min(arr[size/2-1],arr[size/2]) << "\n";
        }
        
    }
    
    
    return 0;
}
