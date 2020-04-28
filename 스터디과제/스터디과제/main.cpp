#include <iostream>
#include <list>
#include <string>
#include <utility>

using namespace std;
typedef pair<string,string> Pair;

list<Pair> arr;

void menu(){
    cout << "-------------------" << "\n";
    cout << "1. 초기화" << "\n";
    cout << "2. 전화 번호 추가" << "\n";
    cout << "3. 전화 번호 탐색" << "\n";
    cout << "4. 종료" << "\n";
    cout << "-------------------" << "\n";
}

void reset(){
    arr.clear();
    cout << "모든 번호가 초기화 되었습니다." << "\n";
}

void insert(){
    string name, number;
    cout << "이름 : ";
    cin >> name;
    cout << "번호 : ";
    cin >> number;
    arr.push_back({name,number});
}

string search(){
    string search_data, value = " ";
    cout << "찾을 이름 : ";
    cin >> search_data;
    
    for(auto it : arr){
        if(search_data == it.first){
            value = it.second;
            break;
        }
    }
    
    if(value == " "){
        value = "찾는 번호가 조회되지 않습니다.";
    }
    return value;
}

int main() {
    
    int input_data = 0;
    
    cout << "연결 리스트를 이용한 전화 번호부 메뉴" << "\n";
    
    while(1){
        menu();
        cin >> input_data;
        
        if(input_data == 1){
            reset();
        }
        else if(input_data == 2){
            insert();
        }
        else if(input_data == 3){
            cout << search() << "\n";
        }
        else{
            cout << "감사합니다" << "\n";
            break;
        }
        
    }
    
    return 0;
}
