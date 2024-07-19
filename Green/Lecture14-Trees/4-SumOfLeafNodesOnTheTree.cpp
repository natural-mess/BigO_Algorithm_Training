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

int sumLeafNode(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int sumL = 0, sumR = 0; 
	if (root->left != NULL) 
    {
		sumL = sumLeafNode(root->left); 
	}
	if (root->right != NULL) 
    {
		sumR = sumLeafNode(root->right); 
	}

	return sumL + sumR; 
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
    cout << sumLeafNode(root);
    
    freeTree(root);
    return 0;
}