#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    
    list<int> arr;
    list<int> :: iterator iter;
    int value = 0, k = 0;
    
    cin >> value >> k;
    
    while(value != 0){
        arr.push_front(value%10);
        value /= 10;
    }
    
    for(int i=0;i<k;i++){
        iter = min_element(arr.begin(), arr.end());
        arr.erase(iter);
    }
    for(auto it : arr){
        cout << it;
    }
    cout << endl;
    
    return 0;
}
