//3n+1

#include <iostream>
#include <climits>

using namespace std;

int main() {
    
    int a = 0, b = 0, max = INT_MIN, max_value = 0;
    int count = 1, data = 0;
    
    cin >> a >> b;
    
    for(int i=a;i<=b;i++){
        count = 1;
        data = i;
        while(data != 1){
            if(data % 2 == 0){
                data /= 2;
            }
            else if(data % 2 == 1){
                data = (data * 3) + 1;
            }
            count += 1;
        }
        if(max < count){
            max = count;
            max_value = i;
        }
        
    }
    
    cout << max_value << " " << max << endl;
    
    
    return 0;
}
