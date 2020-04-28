#include <iostream>

using namespace std;

int main() {
    
    int arr[100000] = {0,};
    int c = 0, n = 0, count = 0;
    
    cin >> n >> c;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<n;i++){
        if(arr[i] - arr[i-1] <= c){
            count += 1;
        }
        else{
            count = 0;
        }
    }
    
    cout << count + 1 << endl;
    
    return 0;
}
