#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char input_data[100][100];

void My_sort(int N){
    
    int idx=0;
    int check=0;
    int len=0;
   
    for(int i=0;i<N;i++){
        for(int j=0;j<N-i-1;j++){
            len=strlen(input_data[j]);
            cout << "--------------------------------" << endl;
            cout << "before : " << input_data[j] << " " << input_data[j+1] << endl;
            
            if(strlen(input_data[j])>strlen(input_data[j+1])){
                swap(input_data[j],input_data[j+1]);
            }
            else if(strlen(input_data[j])==strlen(input_data[j+1])){
                check=0;
                idx=0;
                while(check!=1 && idx < len){
                    if(input_data[j][idx]>input_data[j+1][idx]){
                        swap(input_data[j],input_data[j+1]);
                        check=1;
                    }
                    else if(input_data[j][idx]<input_data[j+1][idx]){
                        break;
                    }
                    idx+=1;
                }
            }
            cout << "after : " << input_data[j] << " " << input_data[j+1] <<endl;
            cout << "--------------------------------" << endl;
        }
    }
}

int main() {
    
    int N=0;
    
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> input_data[i];
    }
    
    My_sort(N);
    
    cout << "=======================" << endl;
    
    for(int i=0;i<N;i++){
        cout << input_data[i] << endl;
    }
    
    return 0;
}
