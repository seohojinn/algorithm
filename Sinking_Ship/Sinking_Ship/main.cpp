#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    
    string name, status;
    int N = 0;
    vector<string> captain, woman, man, rat;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> name >> status;
        if(status == "captain"){
            captain.push_back(name);
        }
        else if(status == "woman" || status == "child"){
            woman.push_back(name);
        }
        else if(status == "rat"){
            rat.push_back(name);
        }
        else{
            man.push_back(name);
        }
    }
    
    for(auto it : rat){
        cout << it << "\n";
    }
    
    for(auto it : woman){
        cout << it << "\n";
    }
    
    for(auto it : man){
        cout << it << "\n";
    }
    
    for(auto it : captain){
        cout << it << "\n";
    }
    
    
    return 0;
}
