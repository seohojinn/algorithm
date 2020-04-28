#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int size, bit_front, bit_end;

int func(int idx, int data){
    int tmp = 0;
    if(idx == bit_end){
        tmp = arr[idx];
        arr[idx] = data;
        bit_end -= 1;
        return tmp;
    }
    else{
        tmp = func(idx+1,data);
    }
    if(idx == bit_front){
        arr[idx] = tmp;
    }
    return tmp;
}

int main() {
    
    int data = 0, N = 0, dummy = 0;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> data;
        arr.push_back(data);
    }
    
    size = int(arr.size());
    bit_end = size - 1;
    
    dummy = func(0,arr[0]);
    
    for(auto it : arr){
        cout << it << " ";
    }
    cout << "\n";
    
    return 0;
}
