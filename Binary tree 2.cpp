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



    Node* findmin(Node* curr){
        if ( curr->left != NULL) findmin(curr->left);
        else return curr;
    }

    void rwp(Node* curr,Node* temp){
        //find current is left or right child
        if(curr == curr->parent->left) curr->parent->left = temp;
        else if(curr == curr->parent->right) curr->parent->right = temp;

    }

    void deletenode(int data){
        //function to search the data and store the pointer
        Node* temp = Search(data);

        //if it has no kids when it's a leaf node
        if( temp->left == NULL && temp->right == NULL){
        //find it's roht or keft child of the parent then point the parent's left or right to null
            if(temp == temp->parent->left) temp->parent->left = NULL;
            else if(temp == temp->parent->right) temp->parent->right = NULL;
            delete temp;
        }
        //Case of node with exactly one child
        else if(temp->left == NULL || temp->right == NULL ){
        //find it's right or left child of the parent
            if(temp == temp->parent->left){
                if(temp->left == NULL)temp->parent->left = temp->right;
                else temp->parent->left = temp->left;
            }
            else if(temp == temp->parent->right){
                if(temp->left == NULL)temp->parent->right = temp->right;
                else temp->parent->right = temp->left;
            }
            delete temp;
        }
        //case of node with 2 children
        else if(temp->left != NULL && temp->right != NULL){
            Node* curr = findmin(temp->right);
            temp->data = curr->data;
            //now to delete durr
            //in case curr is the leaf node
            if( curr->left == NULL && curr->right == NULL){
            //find it's roht or keft child of the parent then point the parent's left or right to null
                if(curr == curr->parent->left) curr->parent->left = NULL;
                else if(curr == curr->parent->right) curr->parent->right = NULL;
                delete curr;
            }
            else if(curr->left == NULL || curr->right == NULL ){
                //find it's right or left child of the parent
                if(curr == curr->parent->left){
                    if(curr->left == NULL)curr->parent->left = curr->right;
                    else curr->parent->left = curr->left;
                }
                else if(curr == curr->parent->right){
                    if(curr->left == NULL)curr->parent->right = curr->right;
                    else curr->parent->right = curr->left;
                }
                delete curr;
            }
        }
    }

};

int main(){
    Tree t1;
    t1.Insert(45);
    t1.Insert(35);
    t1.Insert(56);
    t1.Insert(50);
    t1.Insert(65);
    t1.Insert(22);
    t1.Insert(28);
    t1.Insert(38);
    t1.Insert(46);
    t1.Insert(54);
    t1.Insert(60);
    t1.Insert(70);
    t1.display();
    cout<< (t1.Search(65))->data <<endl;
    cout<< (t1.findmin(t1.root->right))->data <<endl;
    cout << (t1.root->right)->data << endl;
    cout << (t1.root)->data << endl;
    t1.display();
    //cout<< t1.countnode(t1.root) <<endl;
    t1.deletenode(56);
    t1.display();
    return 0;

}

