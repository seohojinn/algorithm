#include <iostream>
#include <queue>

using namespace std;

class Node{ // Node class 정의
    public:
        Node * right; // node의 오른쪽 자식
        Node * left; // node의 왼쪽 자식
        Node * parent; // node 부모 node
        int value;
    
        Node(int data){ //생성자를 통한 초기화
            right = NULL;
            left = NULL;
            parent = NULL;
            value = data;
        }
        
};

class Tree{
    private:
        Node * root;
    
    public:
        Tree(){
            root = NULL;
        }
        void node_insert(Node * data);
        void node_delete(Node * data);
        //void print_node();
        void pre_order(Node * data);
        void in_order(Node * data);
        void post_order(Node * data);
};

void Tree::node_insert(Node * data){
    Node * parent_node;
    if(root == NULL){
        root = data; // 최상위 노드가 없을 경우 최상위 노드 결정
    }
    else{
        parent_node = root; // 루트노드를 가리킴
        while(1){
            if(parent_node->value > data->value){
                if(parent_node->left == NULL){
                    parent_node->left = data;
                    data->parent = parent_node;
                    break;
                }
                else{
                    parent_node = parent_node->left;
                }
            }
            
            else if(parent_node->value < data->value){
                if(parent_node->right == NULL){
                    parent_node->right = data;
                    data->parent = parent_node;
                    break;
                }
                else{
                    parent_node = parent_node->right;
                }
            }
        }
    }
}

void Tree::node_delete(Node *delete_node){
    
    Node * tmp_node;
    Node * tmp_node2;
    Node * tmp_node3;

    tmp_node = delete_node;
    
    if(delete_node->right == NULL && delete_node->left == NULL){
        tmp_node = tmp_node->parent;
        if(tmp_node->right != NULL && tmp_node->right->value == delete_node->value){
            tmp_node->right = NULL;
        }
        else if(tmp_node->left != NULL && tmp_node->left->value == delete_node->value){
            tmp_node->left = NULL;
        }
        delete_node->parent = NULL;
    }

    else{
        if(delete_node->right == NULL){
            tmp_node = tmp_node->left;
            while(tmp_node->right != NULL){
                tmp_node = tmp_node->right;
            }
        }

        else{
            tmp_node = tmp_node->right;
            while(tmp_node->left != NULL){
                tmp_node = tmp_node->left;
            }
        }
            
        if(delete_node == root){
            root = tmp_node;
        }
        tmp_node2 = tmp_node;//
        tmp_node2 = tmp_node2->parent;

        if(tmp_node2->right != NULL && tmp_node2->right->value == tmp_node->value){
            tmp_node2->right = NULL;
        }
        else if(tmp_node2->left != NULL && tmp_node2->left->value == tmp_node->value){
            tmp_node2->left = NULL;
            cout << "ok" << endl;
        }

        tmp_node->left = delete_node->left;
        tmp_node->right = delete_node->right;
        tmp_node->parent = delete_node->parent;

        tmp_node3 = delete_node;

        tmp_node3 = tmp_node3->parent;
        if(tmp_node3!=NULL){
            if(tmp_node3->left->value == tmp_node2->value){
                tmp_node3->left = tmp_node;
            }
            else if(tmp_node3->right->value == tmp_node2->value){
                tmp_node3->right = tmp_node;
            }
        }
        delete_node->left=NULL;
        delete_node->right=NULL;
        delete_node->parent=NULL;
    }
}

void Tree::print_node(){
    
    queue<Node*> print_data;
    int queue_size;
    
    print_data.push(root);
    
    while(!print_data.empty()){
        queue_size= int(print_data.size());
        for(int i=0;i<queue_size;i++){
            if(print_data.front()->left!=NULL){
                print_data.push(print_data.front()->left);
            }
            if(print_data.front()->right!=NULL){
                print_data.push(print_data.front()->right);
            }
            cout << print_data.front()->value << " ";
            print_data.pop();
        }
        cout << endl;
    }
}

void Tree::pre_order(Node * data){
    
    cout << data->value << endl;
    
    if(data->left != NULL){
        pre_order(data->left);
    }

    if(data->right != NULL){
        pre_order(data->right);
    }
}

void Tree::in_order(Node * data){
    
    if(data->left != NULL){
        in_order(data->left);
    }
    cout << data->value << endl;
    
    if(data->right != NULL){
        in_order(data->right);
    }
    
}

void Tree::post_order(Node * data){
    
    if(data->left != NULL){
        post_order(data->left);
    }
    
    if(data->right != NULL){
        post_order(data->right);
    }
    
    cout << data->value << endl;
}

int main() {

    Node root_one(10);
    Node two(5);
    Node three(79);
    Node four(4);
    Node five(19);
    Node six(111);
    
    Tree guard;
    
    guard.node_insert(&root_one);
    guard.node_insert(&two);
    guard.node_insert(&three);
    guard.node_insert(&four);
    guard.node_insert(&five);
    guard.node_insert(&six);
    
//    guard.pre_order(&root_one);
//    cout << root_one.left->left->value << endl;
//    guard.in_order(&root_one);
    guard.post_order(&root_one);
    
    return 0;
}
