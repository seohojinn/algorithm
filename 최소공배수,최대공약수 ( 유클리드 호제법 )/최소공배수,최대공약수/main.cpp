// 최소공배수, 최대공약수

#include <iostream>

using namespace std;

int main() {
    
    int a = 0, b = 0, tmp = 0;
    int A = 0,B = 0;
    cin >> a >> b;
    
    A = a;
    B = b;
    
    while(b != 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    
    cout << a << endl;
    cout << A*B / a << endl;
    
    
    return 0;
}
