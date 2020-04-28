#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N = 0, data = 0;
    vector<int> arr;
    int value = 0, bit = 0;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> data;
        arr.push_back(data);
    }
    
    value = *max_element(arr.begin(), arr.end());
    
    while(1){
        bit = 0;
        for(auto it : arr){
            if(value % it != 0){
                bit = 1;
                break;
            }
        }
        if(bit == 0){
            break;
        }
        value += 1;
    }
    
    cout << value << "\n";
    
    
    return 0;
}
