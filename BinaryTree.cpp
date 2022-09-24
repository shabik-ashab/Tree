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
    chk += to_string(root->data);
    inOrder(root->rightChild, chk);
}

// root -> left -> right
void preOrder(treeNode *root, string &chk)
{
    if (root == NULL)
        return;

    chk += to_string(root->data);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
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

void verticalOrder(treeNode* root,int d,map<int,vector<int>> &m){
    if(root == NULL) return;
    
    m[d].push_back(root->data);
    verticalOrder(root->leftChild,d-1,m);
    verticalOrder(root->rightChild,d+1,m);
}


int main()
{

    // int n;
    // cin >> n;

    // treeNode *allNodes[n];

    // for (int i = 0; i < n; i++)
    // {
    //     allNodes[i] = new treeNode(-1);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int val, left, right;
    //     cin >> val >> left >> right;

    //     allNodes[i]->data = val;

    //     if (left > n - 1 || right > n - 1)
    //     {
    //         cout << "Invalid index" << endl;
    //         break;
    //     }

    //     if (left != -1)
    //     {
    //         allNodes[i]->leftChild = allNodes[left];
    //     }

    //     if (right != -1)
    //     {
    //         allNodes[i]->rightChild = allNodes[right];
    //     }
    // }

    int a;
    cin>>a;
    treeNode* root = new treeNode(a);
    queue<treeNode *> q;

    q.push(root);

    while(!q.empty()){
        treeNode* presentRoot = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        treeNode* n1 = NULL;
        treeNode* n2 = NULL;

        if(x!= -1) n1 = new treeNode(x);
        if(y!= -1) n2 = new treeNode(y);

        presentRoot->leftChild = n1;
        presentRoot->rightChild = n2;

        if(n1 != NULL) q.push(n1);
        if(n2 != NULL) q.push(n2);
    }


    // printTree(allNodes[0], 0);

    string inOrderTraversal = "";
    string preOrderTraversal = "";
    string postOrderTraversal = "";
    string levelOrderTraversal = "";

    int searchVal = 2;

    // inOrder(root, inOrderTraversal);
    // preOrder(root, preOrderTraversal);
    // postOrder(root, postOrderTraversal);
    // int maxValAtK = levelOrder(root, levelOrderTraversal, searchVal);

    // cout << "Inorder Traversal: " << inOrderTraversal << endl;
    // cout << "PreOrderTraversal Traversal: " << preOrderTraversal << endl;
    // cout << "PostOrderTraversal Traversal: " << postOrderTraversal << endl;
    // cout << "levelOrderTraversal Traversal: " << levelOrderTraversal << endl;
    //  cout<<"max value at level 2: "<< maxValAtK<<endl;


    // boundery(allNodes[0]);


    map<int,vector<int>> m;

    verticalOrder(root,0,m);

    // map<int,vector<int>> :: iterator it;

    // for(it = m.begin())

    for(auto e:m){
        for(int j=0;j<(e.second).size();j++){
            cout<<(e.second)[j]<<" ";
        }

        cout<<endl;
    }

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

/*
15
11 26
8 12 20 30
6 9 -1 14 -1 -1 -1 35
-1 -1 -1 -1 -1 -1 -1 -1

*/