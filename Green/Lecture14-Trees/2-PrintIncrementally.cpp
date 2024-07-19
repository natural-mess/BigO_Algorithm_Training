#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int val)
{
    Node *res = new Node;
    res->data = val;
    res->left = NULL;
    res->right = NULL;
    return res;
}

void insertBST(Node *&root, int val)
{
    if (root == NULL)
    {
        root = createNode(val);
        return;
    }

    if (val < root->data)
    {
        insertBST(root->left, val);
    }
    else
    {
        insertBST(root->right, val);
    }
}

void printTreeIncreOrder(Node *root)
{
    if (root->left != NULL)
        printTreeIncreOrder(root->left);

    cout << root->data << " ";
    
    if (root->right != NULL)
        printTreeIncreOrder(root->right);
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    Node *root = NULL;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        insertBST(root, a[i]);
    }
    printTreeIncreOrder(root);
    freeTree(root);
    return 0;
}