#include <iostream>

using namespace std;

void insertion_sort(int * arr, int N){
    
    int key = 0;
    
    for(int i=1;i<N;i++){
        
        key = arr[i];   // i 번째 값을 key 값으로 지정
        
        for(int j=i-1;j>=0;j--){
            if(key < arr[j]){   // 만약 key 값 보다 arr[j] 가 더 크면, arr[j] 값을 한 칸 증가시킴
                arr[j+1] = arr[j];
                arr[j] = 0;
            }
            else if(key >= arr[j]){ // key 값이 arr[j] 보다 더 크면 arr[j+1] 위치에 key 값을 삽입하고 종료
                arr[j+1] = key;
                break;
            }
            
        }
        if(arr[0] == 0){    // 반복문을 한 번 돈 이후 key 값이 삽일 될 위치가 맨 뒤일 경우 맨 뒤에다가 삽입
            arr[0] = key;
        }
    }
}

int main() {
    
    int * arr;  // 동적 메모리 할당할 배열
    int N = 0;  // 원소의 갯수
    
    cin >> N;
    
    arr = new int[N];   // 동적 메모리 할당
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    insertion_sort(arr,N);  // 삽입정렬 함수 호출
    
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";  // 정렬된 원소 출력
    }
    cout << endl;

    delete [] arr;  // 동적 메모리 해제
    
    return 0;
}
