#include <stdio.h>

int front;
int back=1,count=1;
int m,n,v;
int adj[1000][10000];

int f(int * check_arr, int i){
    for(int j=0;j<count;j++){
        if(check_arr[j]==i){
            return 0;
        }
    }
    return 1;
}

void push(int * stack, int * check_arr){
    stack[0]=v;
    check_arr[0]=v;
    int x=0;
    while(back>front){
        for(int i=0;i<m;i++){
            x=stack[back-1];
            if(adj[x-1][i]==1 && f(check_arr,i+1)){
                stack[back]=i+1;
                check_arr[count]=i+1;
                adj[x-1][i]=0;
                adj[i][x-1]=0;
                back++;
                count++;
                break;
            }
            else if(i==m-1){
                back--;
            }
        }
    }
}

int main(){
    
    int stack[100]={0,};
    int check_arr[100]={0,};
    int a=0,b=0;
    scanf("%d %d %d",&m,&n,&v);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        adj[a-1][b-1]=1;
        adj[b-1][a-1]=1;
    }

    push(stack,check_arr);

    for(int i=0;i<count;i++){
        printf("%d ",check_arr[i]);
    }
    printf("\n");

    return 0;
}