#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    
    pair<int,int> info = make_pair(0,0);
    int tmp = 0, tmp2 = 0, value = 0;
    vector<int> arr;
    
    cin >> tmp2;
    
    while(tmp2 != 0){
        tmp += tmp2;
        tmp *= 10;
        cin >> tmp2;
    }
    
    tmp /= 10;
    while(tmp != 0){
        value += tmp % 10;
        value *= 10;
        tmp /= 10;
    }

    value /= 10;

    while(value != 0){

        if(info.first == 0){
            info.first = value % 10;
            info.second = 1;
        }
        else if(info.first != 0){
            if(info.first == value % 10){
                info.second += 1;
            }
            else if(info.first != value % 10){
                if(info.first == 1){
                    arr.push_back(info.second);
                    arr.push_back(info.first);
                }
                else if(info.second == 1){
                    arr.push_back(info.second);
                    arr.push_back(info.first);
                }
                else{
                    arr.push_back(info.first);
                    arr.push_back(info.second);

                }
                info.first = value % 10;
                info.second = 1;
            }
        }
        value /= 10;
    }

    if(info.first == 1){
        arr.push_back(info.second);
        arr.push_back(info.first);
    }
    else if(info.second == 1){
        arr.push_back(info.second);
        arr.push_back(info.first);
    }
    else{
        arr.push_back(info.first);
        arr.push_back(info.second);

    }

    for(auto it : arr){
        cout << it << " ";
    }
    
    cout << endl;

    
    return 0;
}
