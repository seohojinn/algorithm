#include <iostream>
#include <deque>

using namespace std;

int arr[10001];

int solve(int data){
    
    deque<int> value;
    int size = 0;
    
    while(data != 0){
        value.push_front(data % 10);
        data /= 10;
    }
    
    size = int(value.size());
    
    for(int i=0;i<size;i++){
        data = 0;
        for(int j=i;j<size;j++){
            data += value[j];
            data *= 10;
        }
        
        data /= 10;
      
        if(arr[data] == 0){
            return 0;
        }
    }
    
    return 1;
    
}

int main() {
    
    int idx = 0;
    
    for(int i=2;i<=10000;i++){
        arr[i] = i;
    }
    
    for(int i=2;i<=10000;i++){
        idx = i * 2;
        if(arr[i] != 0){
            while(idx <= 10000){
                arr[idx] = 0;
                idx += i;
            }
        }
   
    }
    
    for(int i=1;i<=10000;i++){
        if(solve(i) == 1){
            cout << i << "\n";
        }

    }

    
    return 0;
}
