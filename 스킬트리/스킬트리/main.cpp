#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string input;
    string arr[4];
    int value = 0, tmp = -1, tmp2 = -2, size = 0, size2 = 0;
    
    cin >> input;
    
    for(int i=0;i<4;i++){
        cin >> arr[i];
    }
    
    size = int(input.size());
    
    for(int i=0;i<4;i++){
        size2 = int(arr[i].size());
        for(int j=0;j<size;j++){
            for(int k=0;k<size2;k++){
                if(input[j] == arr[i][k]){
                    tmp = k;
                    break;
                }
            }
            if(tmp2 < tmp){
                tmp2 = tmp;
                break;
            }
            else if(tmp2 > tmp){
                value -= 1;
                break;
            }
        }
        value += 1;
    }
    
    cout << value << "\n";
    
    return 0;
}
