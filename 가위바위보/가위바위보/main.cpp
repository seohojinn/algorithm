#include <iostream>

using namespace std;

int main() {
    
    int arr[5] = {0,};
    int data = 0;
    
    for(int i=0;i<5;i++){
        cin >> data;
        arr[data-1] += 1;
    }
    
    if(arr[0] != 0 && arr[1] != 0 && arr[2] != 0){
        cout << 0 << endl;
    }
    else if(arr[0] == 5 || arr[1] == 5 || arr[2] == 5){
        cout << 0 << endl;
    }
    else{
        if(arr[0] == 0){
            cout << arr[2] << endl;
        }
        else if(arr[1] == 0){
            cout << arr[0] << endl;
        }
        else if(arr[2] == 0){
            cout << arr[1] << endl;
        }
    }
    
    
    return 0;
}
