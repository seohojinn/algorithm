#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string solution(string s,int n) {
    
    char arr[8001] = {0,};
    int size = 0;
    
    size = int(s.size());
    strcpy(arr,s.c_str());
    
    for(int i=0;i<size;i++){
        if(arr[i] != ' '){
            if(arr[i] <= 90 && arr[i] + n > 90){
                arr[i] += n;
                arr[i] = 64 + arr[i] - 90;
            
            }
            else if(arr[i] <= 90 && arr[i] + n <= 90){
                arr[i] += n;
            
            }
            else if(arr[i] <= 122 && arr[i] + n > 122){
                arr[i] += n;
                arr[i] = 96 + arr[i] - 122;
             
            }
            else if(arr[i] <= 122 && arr[i] + n <= 122){
                arr[i] += n;
       
            }
        }
    }
    
    string answer(arr);
    
    return answer;
}

int main(){
    
    int N = 0;
    string a;
    getline(cin,a);
    cin >> N;
    
    cout << solution(a,N) << "\n";
    
    return 0;
}
