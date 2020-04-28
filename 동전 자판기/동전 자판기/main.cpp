#include <iostream>

using namespace std;

int main() {
    
    int data = 0, value = 0;
    int arr[6] = {0,};
    int arr2[6] = {500,100,50,10,5,1};
    int arr3[6] = {0,};
    
    cin >> data;
    
    for(int i=0;i<6;i++){
        cin >> arr[i];
    }
    
    for(int i=5;i>=0;i--){
        if(data == 0){
            break;
        }
        for(int j=arr[i];j>0;j--){
            if(data % (arr2[i] * j) == 0 && data / (arr2[i] * j) <= arr[i] && data / arr2[i] <= arr[i]){
                value += data / arr2[i];
                arr3[i] += data / arr2[i];
                data = 0;
                //cout << "A " << arr2[i] << " " << j << endl;
                break;
            }
            else if(i == 0){
                value += data / arr2[i];
                arr3[i] += data / arr2[i];
                data = 0;
                //cout << "B" << endl;
                break;
            }
            else if(data >= (arr2[i] * j) && (data - (arr2[i] * j)) % arr2[i-1] == 0){
                value += j;
                arr3[i] += j;
                data -= arr2[i] * j;
                //cout << "C" << endl;
                break;
            }
        }
    }
    
    cout << value << endl;
    
    for(auto it : arr3){
        cout << it << " ";
    }
    
    cout << endl;
    
    
    return 0;
}
