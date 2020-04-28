#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int data = 0,value = 0, count = 0;
    vector<int> arr;
    
    arr.push_back(1);
    
    for(int i=2;i<=1500;i++){
        value = i;
        count = 2;
        while(1){
            if(value % count == 0){
                if(count != 2 && count != 3 && count != 5){
                    break;
                }
                value /= count;
                if(value == 1){
                    arr.push_back(i);
                    break;
                }
            }
            else{
                count += 1;
            }
        }
    }
    
   
    cin >> data;
    
    while(data != 0){
        cout << arr[data-1] << endl;
        cin >> data;
    }
    
    return 0;
}
