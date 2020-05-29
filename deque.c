#include <stdio.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node * naxt;
    struct Node * prev;
}Node;

typedef struct Deque{
    Node * head;
    Node * tail;
}Deque;

int size(Deque * dll_pointer){
    Node * cur = dll_pointer->head;
    int return_size=0;
    while(cur){
        return_size++;
        cur=cur->naxt;
    }
    return return_size;
}
int front(Deque * dll_pointer){
    if(!size(dll_pointer)){
        return -1;
    }
    else{
        return dll_pointer->head->data;
    }
}

int back(Deque * dll_pointer){
    if(!size(dll_pointer)){
        return -1;
    }
    else{
        return dll_pointer->tail->data;
    }
}

int empty(Deque * dll_pointer){
    if(!size(dll_pointer)){
        return 1;
    }
    else{
        return 0;
    }
}

int pop_front(Deque * dll_pointer){
    int pop_data=0;
    if(!size(dll_pointer)){
        return -1;
    }
    else if(!dll_pointer->head->naxt){
        pop_data=dll_pointer->head->data;
        dll_pointer->head=NULL;
        dll_pointer->tail=NULL;
        return pop_data;
    }
    else{
        pop_data=dll_pointer->head->data;
        dll_pointer->head=dll_pointer->head->naxt;
        dll_pointer->head->prev->naxt=NULL;
        dll_pointer->head->prev=NULL;
        return pop_data;
    }
}

int pop_back(Deque * dll_pointer){
    int pop_data=0;
    if(!size(dll_pointer)){
        return -1;
    }
    else if(!dll_pointer->tail->prev){
        pop_data=dll_pointer->tail->data;
        dll_pointer->head=NULL;
        dll_pointer->tail=NULL;
        return pop_data;
    }
    else{
        pop_data=dll_pointer->tail->data;
        dll_pointer->tail=dll_pointer->tail->prev;
        dll_pointer->tail->naxt->prev=NULL;
        dll_pointer->tail->naxt=NULL;
        return pop_data;
    }
}

void push_front(Deque * dll_pointer,int push_value, Node * node_data){
    if(!size(dll_pointer)){
        node_data->data=push_value;
        dll_pointer->head=node_data;
        dll_pointer->tail=node_data;
    }
    else{
        node_data->data=push_value;
        node_data->naxt=dll_pointer->head;
        dll_pointer->head->prev=node_data;
        dll_pointer->head=node_data;
    }
}

void push_back(Deque * dll_pointer,int push_value, Node * node_data){
    Node * cur = dll_pointer->head;
    if(!size(dll_pointer)){
        node_data->data=push_value;
        dll_pointer->head=node_data;
        dll_pointer->tail=node_data;
    }
    else{
        node_data->data=push_value;
        while(cur->naxt){
            cur=cur->naxt;
        }
        cur->naxt=node_data;
        node_data->prev=cur;
        dll_pointer->tail=node_data;
    }
}

int main(){
    int N=0;
    int push_value=0;
    int arr_idx=1;
    char command[20]={0,};
    scanf("%d",&N);
    Node arr[10000]={0,};
    Deque real_dll;
    Deque * dll_pointer=&real_dll;
    dll_pointer->head=NULL;
    dll_pointer->tail=NULL;
    for(int i=0;i<N;i++){
        scanf("%s",command);
        if(!strcmp("push_front",command)){
            scanf("%d",&push_value);
            push_front(dll_pointer,push_value,&arr[arr_idx]);
            memset(command,'\0',sizeof(command));
            arr_idx++;
        }
        else if(!strcmp("push_back",command)){
            scanf("%d",&push_value);
            push_back(dll_pointer,push_value,&arr[arr_idx]);
            memset(command,'\0',sizeof(command));
            arr_idx++;
        }
        else if(!strcmp("pop_front",command)){
            printf("%d\n",pop_front(dll_pointer));
        }
        else if(!strcmp("pop_back",command)){
            printf("%d\n",pop_back(dll_pointer));
        }
        else if(!strcmp("size",command)){
            printf("%d\n",size(dll_pointer));
            memset(command,'\0',sizeof(command));
        }
        else if(!strcmp("empty",command)){
            printf("%d\n",empty(dll_pointer));
        }
        else if(!strcmp("front",command)){
            printf("%d\n",front(dll_pointer));
        }
        else if(!strcmp("back",command)){
            printf("%d\n",back(dll_pointer));
        }
    }

    return 0;
}