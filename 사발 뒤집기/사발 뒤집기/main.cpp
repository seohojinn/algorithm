#include <iostream>

using namespace std;

int check(int * arr){
    for(int i=0;i<8;i++){
        if(arr[i] == 1){
            return 1;
        }
    }
    return 0;
}

int main() {
    
    int arr[8] = {0,};
    int count = 0;
    
    for(int i=0;i<8;i++){
        cin >> arr[i];
    }
    
    while(check(arr)){
        for(int i=0;i<8;i++){
            if(i == 6 && arr[i] == 1){
                arr[i] = arr[i] == 1 ? 0 : 1;
                arr[i+1] = arr[i+1] == 1 ? 0 : 1;
                count += 1;
            }
            else if(i == 0 && arr[i] == 1 && arr[i+2] == 0){
                arr[i] = arr[i] == 1 ? 0 : 1;
                arr[i+1] = arr[i+1] == 1 ? 0 : 1;
                count += 1;
            }
            else if(arr[i] == 7){
                arr[i] = arr[i] == 1 ? 0 : 1;
                arr[i-1] = arr[i-1] == 1 ? 0 : 1;
                count += 1;
            }
            else if(arr[i] == 1){
                arr[i] = arr[i] == 1 ? 0 : 1;
                arr[i+1] = arr[i+1] == 1 ? 0 : 1;
                arr[i+2] = arr[i+2] == 1 ? 0 : 1;
                count += 1;
            }
        }
    }
   
    cout << count << endl;
    
    return 0;
}
