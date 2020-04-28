#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>


using namespace std;

int main() {
    
    int arr[7] = {0,};
    int arr2[6] = {0,};
    int count = 0, bonus = 0;
    
    srand(time(NULL));
    
    for(int i=0;i<7;i++){
        arr[i] = rand()%10+1;
    }
    
    sort(arr,arr+7);
    
    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for(int i=0;i<6;i++){
        cin >> arr2[i];
    }
    
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(arr2[i] == arr[j]){
                count += 1;
            }
        }
        if(arr2[i] == arr[6]){
            bonus += 1;
        }
    }
    
    if(count == 6){
        cout << 1 << endl;
    }
    else if(count + bonus > 5){
        cout << 2 << endl;
    }
    else if(count == 5){
        cout << 3 << endl;
    }
    else if(count == 4){
        cout << 4 << endl;
    }
    else if(count == 3){
        cout << 5 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
