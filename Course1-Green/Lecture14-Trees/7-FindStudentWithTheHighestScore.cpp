#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    string mssv;
    string name;
    double score;
    Node *left;
    Node *right;
};

Node *createNode(string mssv, string name, double score)
{
    Node *res = new Node;
    res->mssv = mssv;
    res->name = name;
    res->score = score;
    res->left = NULL;
    res->right = NULL;
    return res;
}

void insertBST(Node *&root, string mssv, string name, double score)
{
    if (root == NULL)
    {
        root = createNode(mssv, name, score);
        return;
    }

    if (score < root->score)
    {
        insertBST(root->left, mssv, name, score);
    }
    else
    {
        insertBST(root->right, mssv, name, score);
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

Node* getHighestScore(Node *root)
{
    if (root->right == NULL)
        return root;
    return getHighestScore(root->right);
}

int main()
{
    int n;
    cin >> n;
    string mssv, name;
    double score;
    Node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> mssv >> name >> score;
        insertBST(root, mssv, name, score);
    }
    root = getHighestScore(root);
    cout << root->mssv << " " << root->name << " " << root->score;

    freeTree(root);
    return 0;
}