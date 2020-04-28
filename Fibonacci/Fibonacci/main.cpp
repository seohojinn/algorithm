//피보나치 수열

#include <iostream>

using namespace std;

int main() {
    
    int n = 0;
    int arr[30] = {1,1,0};
    int sum = 0;
    
    cin >> n;
    
    for(int i=2;i<30;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    
    cout << sum << endl;
    
    return 0;
}
