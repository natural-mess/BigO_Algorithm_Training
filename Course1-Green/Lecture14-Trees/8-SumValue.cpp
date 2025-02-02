#include <bits/stdc++.h>
using namespace std;

struct Node 
{
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

int sumValueLessThanX(Node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->data < x)
    {
        sum = root->data;
    }
    else
    {
        sum = 0;
    }
    
    return sum + sumValueLessThanX(root->left, x) + sumValueLessThanX(root->right, x);
}


int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    Node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        insertBST(root, a[i]);
    }

    cout << sumValueLessThanX(root, x);

    freeTree(root);
    return 0;
}