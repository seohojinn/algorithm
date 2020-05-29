#include <iostream>
#include <algorithm>
#include <vector>

#define LEFT(data) ((data)*2)
#define RIGHT(data) (((data)*2)+1)
#define PARENT(data) ((data)/2)

using namespace std;

class Heap{
    public:
        vector<int> arr;
    
        Heap(){
            arr.push_back(0);
        }
        void insert_heap(int data);
        void delete_heap();
        void print_heap();
};

void Heap::insert_heap(int data){
    size_t insert_node = 0;
    
    arr.push_back(data);
    insert_node = arr.size()-1;
    
    while(insert_node > 1 && arr[insert_node] > arr[PARENT(insert_node)]){
        swap(arr[insert_node],arr[PARENT(insert_node)]);
        insert_node = PARENT(insert_node);
    }
}

void Heap::delete_heap(){
    size_t last_node = arr.size()-1;
    int change_node = 1;
    
    if(last_node == 0){
        return ;
    }
    
    arr[change_node] = arr[last_node];
    arr.pop_back();
    last_node -= 1;
    
    while(1){
        if(LEFT(change_node) <= last_node && arr[LEFT(change_node)] > arr[RIGHT(change_node)] && arr[change_node] < arr[LEFT(change_node)]){
            swap(arr[LEFT(change_node)],arr[change_node]);
            change_node *= 2;
        }
        else if(RIGHT(change_node) <= last_node && arr[LEFT(change_node)] <= arr[RIGHT(change_node)] && arr[change_node] < arr[RIGHT(change_node)]){
            swap(arr[RIGHT(change_node)],arr[change_node]);
            change_node *= 2+1;
        }
        else{
            break;
        }
    }
    
}

void Heap::print_heap(){
    size_t size = arr.size();
    int count = 2;
    cout << "===================" << endl;

    for(int i=1;i<size;i++){
        if(i == count){
            count = count * 2;
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "===================" << endl;
}

void heap_sort(int * arr,int size){
    Heap new_data;
    for(int i=0;i<size;i++){
        new_data.insert_heap(arr[i]);
    }
    new_data.print_heap();
    for(int i=0;i<size;i++){
        arr[i] = new_data.arr[1];
        new_data.delete_heap();
    }
    
}

int main() {
    
    Heap a;
    int n,i;
    int arr[100];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    heap_sort(arr,n);
    cout << "===================" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "===================" << endl;
   
    return 0;
}
