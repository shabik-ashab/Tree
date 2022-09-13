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


int main()
{
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

    printTree(root,0);

    return 0;
}