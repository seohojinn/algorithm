#include <iostream>

using namespace std;

int main() {
    
    int N = 0, M = 0;
    int arr[1000] = {0,};
    int max = -1;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<N;i++){
        if(i + (M-1) > N){
            break;
        }
        if(arr[i] + arr[i+1] + arr[i+2] > max){
            max = arr[i] + arr[i+1] + arr[i+2] ;
        }
    }
    
    cout << max << endl;
    
    return 0;
}
