#include <iostream>

using namespace std;

int main() {
    int A = 0, B = 0, C = 0;
    int value = 0;
    int arr[10] = {0,};
    
    cin >> A >> B >> C;
    
    value = A * B * C;
    
    while(value != 0){
        arr[value % 10] += 1;
        value /= 10;
    }
    
    for(int i=0;i<10;i++){
        cout << arr[i] << endl;
    }
    
    return 0;
}
