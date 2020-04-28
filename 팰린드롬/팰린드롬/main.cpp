#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    
    char arr[2501] = {0,};
    int size = 0, max_data = -1, count = 0, bit = -1, check = 0;
    deque<int> data;
    
    cin >> arr;
    
    size = int(strlen(arr));
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i] == arr[j]){
                for(int k=i;k<=j;k++){
                    data.clear();
                    count = 0;
                    check = 0;
                    for(int l=i;l<=j;l++){
                        if(k != l){
                            data.push_back(arr[l]);
                        }
                    }
                    while(!data.empty()){
                        if(data.size() == 1){
                            count += 1;
                            data.pop_back();
                        }
                        else if(data.front() == data.back()){
                            count += 2;
                            data.pop_front();
                            data.pop_back();
                        }
                        else{
                            check = 1;
                            break;
                        }
                    }
                    if(bit != 1 && check == 0){
                        bit = 0;
                        max_data = max(max_data,count);
                    }
                }
                data.clear();
                count = 0;
                check = 0;
                for(int k=i;k<=j;k++){
                    data.push_back(arr[k]);
                }
                while(!data.empty()){
                    if(data.size() == 1){
                        count += 1;
                        data.pop_back();
                    }
                    else if(data.front() == data.back()){
                        count += 2;
                        data.pop_front();
                        data.pop_back();
                    }
                    else{
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    bit = 1;
                    max_data = max(max_data,count);
                }
            }
        }
    }
    
    if(bit == -1){
        cout << "nono" << endl;
    }
    else if(bit == 0){
        cout << "유사 펥린드롬" << endl;
        cout << max_data << endl;
    }
    else{
        cout << "펠린드롬" << endl;
        cout << max_data << endl;
    }
    
    return 0;
}
