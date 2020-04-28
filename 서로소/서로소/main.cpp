#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    
    FILE * outFile= fopen("input.txt","r");
    
    int arr[10] = {0,};
    int i = 0;
    
    while(fscanf(outFile,"%d",&arr[i])==1){
        i += 1;
    }
    
    for(int j=0;j<i;j++){
        cout << arr[i] << endl;
    }
    
    
    return 0;
}
