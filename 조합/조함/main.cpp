#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    
    vector<string> arr;
    int N = 0;
    unsigned long long max = 0, value = 0;
    string data, tmp;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> data;
        arr.push_back(data);
    }
    
    do{
        tmp = "";
        for(auto it : arr){
            tmp += it;
        }
        value = stoull(tmp);

        if(max < value){
            max = value;
        }
        
    }while(next_permutation(arr.begin(),arr.end()));
    
    cout << max << endl;
    
    return 0;
}
