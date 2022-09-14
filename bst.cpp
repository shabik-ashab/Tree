#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}

// preOrder print tree
void printTree(treeNode *root, int level)
{
    // if tree is empty
    if (root == NULL)
        return;

    // if left and right child is null we found our leaf node
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

// left -> root -> right
void inOrder(treeNode *root, string &chk)
{

    if (root == NULL)
        return;

    inOrder(root->leftChild, chk);
    chk += (to_string(root->data)+" ");
    inOrder(root->rightChild, chk);
}

// root -> left -> right
void preOrderTraversal(treeNode *root, string &chk)
{

    if (root == NULL)
        return;

    chk += to_string(root->data);
    preOrderTraversal(root->leftChild, chk);
    preOrderTraversal(root->rightChild, chk);
}

void postOrder(treeNode *root, string &chk)
{

    if (root == NULL)
        return;

    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += to_string(root->data);
}

// level order traversal
int levelOrder(treeNode *root, string &chk, int k)
{
    if (root == NULL)
        return -1;

    int level = 0;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = INT_MIN;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            if (level == k)
            {
                if (max < chkNode->data)
                    max = chkNode->data;
            }
            chk += to_string(chkNode->data);

            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }

    return max;
}

// Construct a Binary Tree from Preorder and Inorder Traversal
// if pre order and post order is given we can draw our tree

//  Construct a Binary Tree from Postorder and Inorder Traversal

// Construct a Binary Tree from Preorder and Postorder Traversal
// we need a full binary tree to construct binary Tree from Preorder and Postorder Traversal


// traversing boundary of tree 
// we can make 4 different step 
//s1: lb -> non leaves
//s2: lb -> leaves
//s3: rb -> leaves
//s4: rb -> non leaves

void printLeaves(treeNode* root){
    if(root == NULL) return;
    if(root->leftChild == NULL && root->rightChild == NULL){
         cout<<root->data<<" ";
         return;
    }

    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode* root){
    if(root == NULL) return;

    if(root->leftChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }else if(root->rightChild != NULL){
        cout<< root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }

}

void printRightNonLeaves(treeNode* root){
    if(root == NULL) return;

     if(root->rightChild != NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->rightChild);
    }else if(root->leftChild != NULL){
        cout<< root->data<<" ";
        printRightNonLeaves(root->leftChild);
    }
}

void boundery(treeNode* root){
    if(root == NULL) return;
    cout<< root->data<<" ";

    //lb non-leaves
    printLeftNonLeaves(root->leftChild);
    //lb leaves
    printLeaves(root->leftChild);
    //rb leaves
    printLeaves(root->rightChild);
    //rb non-leaves
    printRightNonLeaves(root->rightChild);
}

treeNode* insertionBst(treeNode* root,int val){
    treeNode* newNode = new treeNode(val);

    if(root == NULL){
        root = newNode;
        return root;
    }

    // val < root -> data
    if(val < root->data){
        root->leftChild = insertionBst(root->leftChild, val);
    }
    // val > root->data
    else if(val > root->data){
        root->rightChild = insertionBst(root->rightChild, val);
    }

    return root;
}

treeNode* searchBst(treeNode* root,int val){
    if(root == NULL){
        return NULL;
    }

    if(root->data == val){
        cout<<root->data;
        return root;
    }
    
    else if(val < root->data){
        cout<<root->data<<" -> ";
        searchBst(root->leftChild, val);
    }
    
    else if(val > root->data){
        cout<<root->data<<" -> ";
        searchBst(root->rightChild, val);
    }
}

treeNode* inorderSucc(treeNode* root){
    treeNode* curr = root;

    while(curr->leftChild != NULL){
        curr = curr->leftChild;
    }
    return curr;
}

treeNode* deletionBst(treeNode* root,int val){
    if(val < root->data){
        root->leftChild = deletionBst(root->leftChild, val);
    }
    else if(val > root->data){
        root->rightChild = deletionBst(root->rightChild, val);
    }else{
        if(root->leftChild == NULL){
            treeNode* temp = root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild == NULL){
            treeNode* temp = root->leftChild;
            free(root);
            return temp;
        }
        else{
            treeNode* temp = inorderSucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBst(root->rightChild, temp->data);
        }

        return root;
    }
}

// zigzag traversal
// leftToRight = true
// we need two stack 
// curLevel and nextLevel
/*
we will set node to curlevel
if(ltor == true){
     insert to nextLevel
     toggle ltor
     toggle stack(means curLevel will become next level and vise versa)
    }
else{
    insert to nextLevel from right to left
    toggle ltor
    toggle stack(means curLevel will become next level and vise versa)
}
*/

// psudocode
/*
while(curLevel != empty){
   x = pop() and add to output
   if(ltor == true){
    // we will push to nextLevel
    push(x.left)
    push(x.right)
   }else{
    push(x.right)
    push(x.left)
   }
}
*/

void zigzag(treeNode* root){
    stack<treeNode*> curLevel;
    stack<treeNode*> nextLevel;

    bool leftToR = true;

    curLevel.push(root);
    while(!curLevel.empty()){
        treeNode* x = curLevel.top();
        curLevel.pop();

        cout<<x->data<<" ";

        if(leftToR){
            if(x->leftChild != NULL) nextLevel.push(x->leftChild);
            if(x->rightChild != NULL) nextLevel.push(x->rightChild);
        }else{
            if(x->rightChild != NULL) nextLevel.push(x->rightChild);
            if(x->leftChild != NULL) nextLevel.push(x->leftChild);
        }

        if(curLevel.empty()){
            leftToR = !leftToR;
            swap(curLevel,nextLevel);
        }
        
    }
}


int main()
{

    int n;
    cin>>n;

    treeNode* root = NULL;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        root = insertionBst(root,v);
    }

    string inOrderT = "";
    inOrder(root, inOrderT);
    cout<<"inOrder:"<<inOrderT<<endl;

    // int key;
    // cin>>key;

    // if(searchBst(root, key) == NULL){
    //     cout<<"value does not exist"<<endl;
    // }

    // root = deletionBst(root, key);

    // string inOrderA = "";
    // inOrder(root, inOrderA);
    // cout<<"inOrder:"<<inOrderA<<endl;

    zigzag(root);
    

    return 0;
}

/*
10
11 5 9 43 34 1 2 7 8 21
*/

// construct complete binary tree from array
// ith lc -> 2*i+1
// ith rc -> 2*1+2