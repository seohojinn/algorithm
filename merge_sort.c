#include <stdio.h>

void swap(int * arr,int front,int mid, int back){
    int front_idx=front;
    int back_idx=mid;
    int tmp_arr[100]={0,};

    for(int i=front;i<back;i++){
        if(front_idx==mid){
            for(int j=i;j<back;j++){
                tmp_arr[j]=arr[back_idx];
                back_idx++;
            }
            break;
        }
        else if(back_idx==back){
            for(int j=i;j<back;j++){
                tmp_arr[j]=arr[front_idx];
                front_idx++;
            }
            break;
        }
        else if(arr[front_idx]>arr[back_idx]){
            tmp_arr[i]=arr[back_idx];
            back_idx++;
        }
        else if(arr[front_idx]<arr[back_idx]){
            tmp_arr[i]=arr[front_idx];
            front_idx++;
        }
    }
    for(int i=front;i<back;i++){
        arr[i]=tmp_arr[i];
    }

}

void merge_sort(int * arr,int front, int back){
    int mid=(front+back)/2;
    
    if(back>front){
        merge_sort(arr,front,mid);
        merge_sort(arr,mid+1,back);
        swap(arr,front,mid+1,back+1);
    }
}

int main(){
    int arr[100]={0,};
    int n=0;
    int front=0,back=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    back=n-1;
    merge_sort(arr,front,back);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    puts("");

    return 0;

}