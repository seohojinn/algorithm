#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n = 0;
    vector<int> arr;
    size_t size = 0;
    
    cin >> n;
    
    arr.push_back(2);
    for(int i=3;i<=n/2;i++){
        for(int j=2;j<i;j++){
            if(i % j == 0){
                break;
            }
            else if(j == i-1){
                arr.push_back(i);
            }
        }
    }
    size = arr.size();
    
    for(size_t i=0;i<size;i++){
        for(size_t j=1;j<size;j++){
            if(arr[i] * arr[j] == n){
                cout << arr[i] << " " << arr[j] << endl;
                return 0;
            }
        }
    }
    
    cout << "wrong number" << endl;
    
    
    return 0;
}
