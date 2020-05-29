#include <iostream>
#include <deque>

using namespace std;

class Queue{
public:
    int front;
    int back;
    int value[100];
    Queue(){
        front = 0;
        back = 0;
    }
    void clear(){
        front = 0;
        back = 0;
    }
    void push(int data){
        value[back] = data;
        back += 1;
    }
    void pop(){
        back -= 1;
    }
    int size(){
        return back - front;
    }
};

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Queue arr;
    
    int T = 0, N = 0, M = 0, data = 0, count = 0, size = 0, tmp_value = 0;
    int bit = 0;
    
    cin >> T;
    
    for(int i=0;i<T;i++){
        
        cin >> N >> M;
        count = 0;
        arr.clear();
        
        for(int j=0;j<N;j++){
            cin >> data;
            arr.push(data);
        }
        
        tmp_value = arr.value[M];
        
        while(1){
            size = arr.size();
            bit = 0;
            count += 1;
            
            if(size == 1){
                cout << count << "\n";
                break;
            }
            
            if(arr.value[arr.front] == tmp_value && M == arr.front){
                size = arr.size();
                for(int j=1;j<size;j++){
                    if(arr.value[arr.front] < arr.value[arr.front + j]){
                        break;
                    }
                    else if(j == size - 1){
                        //cout << "\n";
                        cout << count << "\n";
                        bit = 1;
                    }
                }
                if(bit == 1){
                    break;
                }
            }
            
            for(int j=1;j<size;j++){
                   
                   if(arr.value[arr.front] < arr.value[arr.front + j]){
                       arr.push(arr.value[arr.front]);
                       arr.pop();
                       
                       M -= 1;
                       count -= 1;
                       
                       if(M == arr.front - 1){
                           M = arr.back - 1;
                       }
                       break;
                   }
                   else if(j == size - 1){
                       M -= 1;
                       if(M == arr.front - 1){
                           M = arr.back - 2;
                       }
            
                       arr.pop();
                   }
               }
        }
            
    }
    
    return 0;
}
