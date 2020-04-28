#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> data;
    int size = int(commands.size());
    int begin = 0, end = 0;
    
    for(int i=0;i<size;i++){
        begin = commands[i][0] - 1;
        end = commands[i][1];
        for(int j=begin;j<end;j++){
            data.push_back(array[j]);
        }
        sort(data.begin(),data.end());
        answer.push_back(data[commands[i][2]-1]);
        data.clear();
    }
    
    return answer;
}

int main() {
    
    ios::sync_with_stdio(false);
    
    vector<int> arr;
    vector<vector<int> > commend;
    int N = 0, data = 0, a = 0, b = 0, k = 0;
    
    cin >> N;
    
    commend.resize(3);
    
    for(int i=0;i<N;i++){
        cin >> data;
        arr.push_back(data);
    }
    
    for(int i=0;i<3;i++){
        cin >> a >> b >> k;
        commend[i].push_back(a);
        commend[i].push_back(b);
        commend[i].push_back(k);
    }
    
    vector<int> value(solution(arr, commend));
    
    for(auto it : value){
        cout << it << " ";
    }
    cout << "\n";
    
    return 0;
}
