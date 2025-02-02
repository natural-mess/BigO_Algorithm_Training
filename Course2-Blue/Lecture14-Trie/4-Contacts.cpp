#include <bits/stdc++.h>
using namespace std;

#define MAX 26

struct Node
{
    struct Node *child[MAX];
    int wordCount;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->wordCount = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node *root, const string &s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        temp->wordCount++;
    }
    
}

int findWord (struct Node *root, const string &s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            return 0;
        }
        temp = temp->child[ch];
    }
    return temp->wordCount;
}

void deletenode(struct Node *pNode)
{
    for (int i = 0; i<MAX; i++)
    {
        if (pNode->child[i])
        {
            deletenode(pNode->child[i]);
            delete pNode->child[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string cmd, content;
    struct Node *root = newNode();
    for (int i = 0; i < n; i++)
    {
        cin >> cmd >> content;
        if (cmd[0] == 'a')
        {
            addWord(root, content);
        }
        else
        {
            cout << findWord(root, content) << endl;
        }
    }
    deletenode(root);

    return 0;
}