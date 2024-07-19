#include<bits/stdc++.h>
using namespace std;
int a[1002], n;

struct Node {
    int data;
    Node *left, *right;
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

int getMin(Node *root)
{
    if (root->left == NULL)
        return root->data;
    return getMin(root->left);
}

int main()
{
    cin >> n;
    Node *root = NULL;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        insertBST(root, a[i]);
    }
    cout << getMin(root);
}