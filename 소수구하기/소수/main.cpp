#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N = 0;
    vector<int> arr;
    int sum = 0;
    cin >> N;
    
    for(int i=2;i<=N;i++){
        for(int j=2;j<=i;j++){
            if(j != i && i%j == 0){
                break;
            }
            else if(i == j){
                arr.push_back(i);
            }
        }
    }
    
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << sum << endl;
    
    return 0;
}
