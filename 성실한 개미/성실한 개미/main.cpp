#include <iostream>
#include <utility>

using namespace std;

int main() {
    
    int arr[10][10] = {0,};
    pair<int,int> lo;
    int bit = 0;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0 && bit == 0){
                lo.first = i;
                lo.second = j;
                bit = 1;
            }
        }
    }
    
    while(arr[lo.first][lo.second] != 2){
        arr[lo.first][lo.second] = 9;
        if(arr[lo.first][lo.second+1] == 0){
            lo.second += 1;
        }
        else{
            lo.first += 1;
        }
    }
    arr[lo.first][lo.second] = 9;
    
    cout << "=============" << endl;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
