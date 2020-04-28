#include <iostream>

using namespace std;

void swap(int & a, int & b){    // 인자를 레퍼런스로 받음
    int c = a;
    a = b;
    b = c;
}

void selection_sort(int * arr, int N){
    
    int min = 0, min_idx = 0;
    
    for(int i=0;i<N-1;i++){
        min = arr[i];   // 최솟값을 인덱스 i 번째 데이터로
        min_idx = i;    // 최솟값의 인덱스를 i로
        for(int j=i+1;j<N;j++){ // i 앞에 있는 데이터들중 가장 작은 값 추출
            if(min > arr[j]){
                min = arr[j];
                min_idx = j;
            }
        }
        
        if(min_idx != i){  // i 앞에 있는 데이터들중 arr[i] 보다 더 작은 값이 있었다면 swap 함수 호출
            swap(arr[i], arr[min_idx]);
        }
    }
    
}

int main() {
    
    int * arr;  // 동적 메모리 할당 할 포인터 변수
    int N = 0;  // 원소의 갯수
    
    cin >> N;
    
    arr = new int[N];   // 동적 메모리 할당
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    selection_sort(arr,N);  // selection_sort 함수 호출
    
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";  // 정렬 후 데이터 출력
    }
    cout << endl;
    
    delete []arr;   // 동적 메모리 헤제
    
    return 0;
}
