#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    //children
    Node* left;
    Node* right;
    Node* parent;

    Node(int val){
    left = NULL;
    right = NULL;
    parent = NULL;
    data = val;
    }

};

class Tree{
    public:

    Node* root;
    Tree(){
        root = NULL;

    }
    void Insert(int val){
        inserthelper(root, val);

    }
    void inserthelper(Node* curr,int val){

        //if the tree is empty

        //Base case if CURR is NULL, insert there
       if(curr == NULL){
            curr  = new Node(val);
            if(root == NULL) root = curr;
            return;
        }
        //compare and move
        else if(curr->data > val){

                if(curr->left == NULL){
                    curr->left = new Node(val);
                    (curr->left)->parent =  curr;
                }
                else inserthelper(curr->left, val);
        }
        else if(curr->data < val){

                if(curr->right == NULL){
                    curr->right = new Node(val);
                    (curr->right)->parent = curr;
                }
                else inserthelper(curr->right, val);

        }

    }


    void display(){display2(root);
            cout<<"\n";}
        //display In order - left->middle->right
        //pre order - root->let->right
        //post order - left->right->root
        //calling a display calls a triangle
        //Base Condition
        void display2(Node* curr){
            if(curr->left != NULL) display2(curr->left);
                //display current
                    cout << curr->data <<",";
                    //display right

                if(curr->right != NULL) display2(curr->right);
                else return;
        }

    Node* Search(int val){
        Search2(root, val);
    }
    Node* Search2(Node* curr, int val){
        //base condition
        if(curr == NULL || curr->data == val) return curr;
        //check and return
        else if(curr->data < val)return Search2(curr->right, val);
        else if(curr->data > val) return Search2(curr->left, val);

    }

};

int main(){
    Tree t1;
    t1.Insert(40);
    t1.Insert(35);
    t1.Insert(56);
    t1.Insert(65);
    t1.Insert(22);
    t1.Insert(28);
    t1.display();
    cout<< (t1.Search(28))->data <<endl;
    //cout<< (t1.findmin2(t1.root))->data <<endl;
    //cout<< t1.countnode(t1.root) <<endl;
    return 0;

}

