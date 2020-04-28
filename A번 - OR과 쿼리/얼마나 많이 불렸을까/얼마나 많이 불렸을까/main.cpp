#include <iostream>

using namespace std;

int main() {
    
    int N = 0, data = 0;
    int value[10] = {0,};
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> data;
        if(0 < data && data < 11){
            value[data-1] += 1;
        }
    }
    
    for(int i=0;i<10;i++){
        cout << value[i];
    }
    
    cout << endl;
    
    return 0;
}
