#include <iostream>

using namespace std;

int main() {
    
    int N = 0, K = 0, M = 0;
    int num = 0, l = 0, r = 0, x = 0, count = 0;
    int arr[250000] = {0,};
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    cin >> M;
    
    for(int i=0;i<M;i++){
        cin >> num;
        if(num == 1){
            cin >> l >> r >> x;
            for(int i=l-1;i<r;i++){
                arr[i] = arr[i] | x;
            }
        }
        else{
            cin >> l >> r;
            count = 0;
            for(int i=l-1;i<r;i++){
                if(arr[i] == K){
                    count += 1;
                }
            }
            cout << count << "\n";
            
        }
    }
    
    return 0;
}
