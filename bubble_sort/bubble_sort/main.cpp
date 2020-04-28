#include <iostream>

using namespace std;

void swap(int & a, int & b){    // 인자를 레퍼런스로 받음
    int c = a;
    a = b;
    b = c;
}

int main() {
    
    int * arr;  // 동적으로 메모리를 할당할 포인터 변수
    int N = 0;  // 원소의 갯수
    
    cin >> N;         // N을 입력 
    arr = new int[N]; // N * 4 byte 만큼 동적 메모리 할당
    
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    cout << "----- before -----" << endl;
    
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";  // 정렬하기 이전 값 출력
    }
    cout << endl << endl;
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1-i;j++){
            if(arr[j] > arr[j+1]){ // arr[j] 가 arr[j+1] 보다 더 클경우 swap 함수 호출
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    cout << "----- after -----" << endl;
    
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";  // 정렬한 이후 값 출력
    }
    cout << endl;
    
    delete [] arr;  // 동적 메모리 해제
    
    return 0;
}
