#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> arr;
    int n = 0, idx = 0;
    
    cin >> n;
    
    arr.push_back(2);
    
    for(int i=3;i<=n;i++){
        for(int j=2;j<i;j++){
            if(i % j == 0){
                break;
            }
            else if(j == i-1){
                arr.push_back(i);
            }
        }
    }
    
    while(n != 1){
        if(n % arr[idx] == 0){
            n /= arr[idx];
            cout << arr[idx] << " ";
        }
        else{
            idx += 1;
        }
    }
    
    cout << endl;
    
    return 0;
}
