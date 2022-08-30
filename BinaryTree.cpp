#include <bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int val){
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level){
    for(int i=0;i<level;i++){
        cout<<"    ";
    }
}

// preOrder print tree
void printTree(treeNode* root, int level){
    // if tree is empty
    if(root == NULL) return;

    // if left and right child is null we found our leaf node
    if(root->leftChild == NULL && root->rightChild == NULL){
        cout<<root->data<<endl;
    }else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->leftChild != NULL){
        spacePrint(level);
        cout<< "Left: ";
        printTree(root->leftChild, level + 1);
    }
   
    if(root->rightChild != NULL){
    spacePrint(level);
    cout<< "Right: ";
    printTree(root->rightChild, level + 1);
    }        
}

void inOrder(treeNode* root, string &chk){

    if(root == NULL) return;

    inOrder(root->leftChild,chk);
    chk += to_string(root->data);
    inOrder(root->rightChild,chk);
}

void preOrder(treeNode* root, string &chk){

    if(root == NULL) return;

    chk += to_string(root->data);
    inOrder(root->leftChild,chk);
    inOrder(root->rightChild,chk);
}

int main()
{
    
    int n;
    cin>>n;

    treeNode* allNodes[n];

    for(int i=0;i<n;i++){
        allNodes[i] = new treeNode(-1);
    }    

    for(int i=0;i<n;i++){
        int val,left,right;
        cin>>val>>left>>right;

        allNodes[i]->data = val;

        if(left>n-1 || right>n-1){
            cout<<"Invalid index"<<endl;
            break;
        }

        if(left!=-1){
            allNodes[i]->leftChild = allNodes[left];
        }

        if(right!=-1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }  

    printTree(allNodes[0], 0);

    string inOrderTraversal = "";
    inOrder(allNodes[0], inOrderTraversal);

    cout<<"Inorder Traversal: "<<inOrderTraversal<<endl;

    return 0;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1 
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

*/