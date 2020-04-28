#include <iostream>
#include <algorithm>

using namespace std;

class Node{             // Tree의 노드 class
    public:
        Node * right;
        Node * left;
        Node * parent;
        int value;
        Node(int data){
            right = NULL;
            left = NULL;
            parent = NULL;
            value = data;
        }
};

class Tree{            //Tree의 삽입, 삭제, 순회를 관리하는 class
    public:
        Node * root;
        Tree(){
            root = NULL;
        }
        void node_insert(Node * insert_data);  // 새로운 노드를 삽입
        void node_delete(Node * delete_node);  // 노드를 삭제
        void pre_order(Node * data); // root -> left -> right 순서로 순회
        void in_order(Node * data); // left -> root -> right 순서로 순회
        void post_order(Node * data); // left-> right -> root 순서로 순회

};

void Tree::node_insert(Node * insert_data){
    
    Node * parent_node = root;  // 삽입할 노드의 부모가 될 노드
    
    if(root == NULL){   // root 를 가르키는 노드가 NULL 일 경우 root node 지정
        root = insert_data;
        return ;
    }

    while(1){
        if(insert_data->value > parent_node->value){   // 삽입할 노드의 데이터 보다 현재 가르키고 있는 노드의 값이 더 클 경우
            if(parent_node->right == NULL){ // 현재 가르키고 있는 노드의 오른쪽 자손이 없을 경우 노드를 삽입하고 종료
                parent_node->right = insert_data;
                insert_data->parent = parent_node;
                break;
            }
            else{
                parent_node = parent_node->right; // 현재 가르키고 있는 노드의 오른쪽 자손이 있을 경우 오른쪽 노드로 이동
            }
        }
        else if(insert_data->value < parent_node->value){ // 삽입할 노드의 데이터 보다 현재 가르키고 있는 노드의 값이 더 작을 경우
            if(parent_node->left == NULL){  // 현재 가르키고 있는 노드의 왼쪽 자손이 없을 경우 노드를 삽입하고 종료
                parent_node->left = insert_data;
                insert_data->parent = parent_node;
                break;
            }
            else{
                parent_node = parent_node->left; // 현재 가르키고 있는 노드의 왼쪽 자손이 있을 경우 왼쪽 노드로 이동
            }
        }
    }
}

void Tree::node_delete(Node * delete_node){
    
    Node * tmp = delete_node;
    
    // 끊을려는 노드의 자식들이 양쪽 다 없을 경우
    if(delete_node->left == NULL && delete_node->right == NULL){    // 삭제하는 노드의 오른쪽, 왼쪽 자손 노드가 없을 경우
        if(delete_node->parent == NULL){    // 삭제하는 노드가 루트노드일 경우
            root = NULL;
        }
        else{
            tmp = tmp->parent; // 삭제할려는 노드의 부모 노드로 이동
            if(tmp->right != NULL && tmp->right->value == delete_node->value){  // 부모 노드에서 오른쪽 노드가 삭제할려는 노드면 노드 삭제
                tmp->right = NULL;
            }
            else if(tmp->left != NULL && tmp->left->value == delete_node->value){ // 부모 노드에서 왼쪽 노드가 삭제할려는 노드면 노드 삭제
                tmp->left = NULL;
            }
            delete_node->parent = NULL; // 삭제 당하는 노드에서 부모 노드와 연결 끊기
        }
    }
    
    // 끊을려는 노드의 자식이 왼쪽만 없을 경우
    else if(delete_node->left == NULL){
        tmp = tmp->right;
        tmp->parent = tmp->parent->parent;
        if(tmp->parent != NULL && tmp->parent->left->value == delete_node->value){
            tmp->parent->left = tmp;
        }
        else if(tmp->parent != NULL && tmp->parent->right->value == delete_node->value){
            tmp->parent->right = tmp;
        }
        delete_node->right = NULL;
        delete_node->parent = NULL;
    }
    
    // 끊을려는 노드의 자식이 오른쪽만 없을 경우
    else if(delete_node->right == NULL){
        tmp = tmp->left;
        tmp->parent = tmp->parent->parent;
        if(tmp->parent != NULL && tmp->parent->left->value == delete_node->value){
            tmp->parent->left = tmp;
        }
        else if(tmp->parent != NULL && tmp->parent->right->value == delete_node->value){
            tmp->parent->right = tmp;
        }
        delete_node->left = NULL;
        delete_node->parent = NULL;
    }
    
    // 끊을려는 노드의 자식이 둘다 있을 경우
    else{
        tmp = tmp->right;
        while(tmp->left != NULL){
            tmp = tmp->left;
        }
        
        swap(delete_node->value,tmp->value);
        
        if(tmp->right == NULL){
            if(tmp->parent->left->value == tmp->value){
                tmp->parent->left = NULL;
                tmp->parent = NULL;
            }
            else{
                tmp->parent->right = NULL;
                tmp->parent = NULL;
            }
        }
        else{
            tmp->right->parent = tmp->parent;
            tmp->parent->left = tmp->right;
            tmp->right = NULL;
            tmp->parent = NULL;
        }
    }
}

void Tree::pre_order(Node * data){   // root -> left -> right 순서로 순회
    
    cout << data->value << endl;
    
    if(data->left != NULL){
        pre_order(data->left);
    }
    if(data->right != NULL){
        pre_order(data->right);
    }
}

void Tree::in_order(Node * data){   // left -> root -> right 순서로 순회
    
    if(data->left != NULL){
        in_order(data->left);
    }
    cout << data->value << endl;
    
    if(data->right != NULL){
        in_order(data->right);
    }
    
}

void Tree::post_order(Node * data){   // left -> right -> root 순서로 순회
    
    if(data->left != NULL){
        post_order(data->left);
    }
    
    if(data->right != NULL){
        post_order(data->right);
    }
    
    cout << data->value << endl;
    
}

int main() {

    Node one(10); //node 객체 생성
    Node two(5);
    Node three(79);
    Node four(4);
    Node five(19);
    Node six(111);
    Node seven(6);
    
    Tree guard; // node 들을 관리하는 객체 생성
    
    guard.node_insert(&one);    //node 삽입
    guard.node_insert(&two);
    guard.node_insert(&three);
    guard.node_insert(&four);
    guard.node_insert(&five);
    guard.node_insert(&six);
    guard.node_insert(&seven);
    
    Node * tmp = guard.root;
    
    while(tmp != NULL){
        cout << tmp->value << endl;
        tmp = tmp->right;
    }
    cout << endl << endl;

    guard.node_delete(&four);
    guard.node_delete(&two);
    tmp = guard.root;

    while(tmp != NULL){
        cout << tmp->value << endl;
        tmp = tmp->left;
    }
    guard.node_delete(&two);
    
    guard.post_order(tmp);
    guard.in_order(tmp);
    guard.pre_order(tmp);
    
    return 0;
}
