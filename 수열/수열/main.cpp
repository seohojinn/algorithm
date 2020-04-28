#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    
    int N = 0;
    int arr[100000] = {0,};
    int max_dp[100000] = {0,};
    int min_dp[100000] = {0,};
    
    max_dp[0] = 1;
    min_dp[0] = 1;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<N;i++){
        if(arr[i] >= arr[i-1]){
            max_dp[i] = max_dp[i-1] + 1;
        }
        else{
            max_dp[i] = 1;
        }
        if(arr[i] <= arr[i-1]){
            min_dp[i] = min_dp[i-1] + 1;
        }
        else{
            min_dp[i] = 1;
        }
    }
    
    cout << max(*max_element(max_dp, max_dp+N), *max_element(min_dp, min_dp+N)) << "\n";
    
    
    return 0;
}
