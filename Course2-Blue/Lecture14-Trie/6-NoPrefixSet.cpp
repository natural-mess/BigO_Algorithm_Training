#include <bits/stdc++.h>
using namespace std;

#define MAX 10 // from a to j

struct Node
{
    struct Node *child[MAX];
    int countWord;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->countWord = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

bool addWord (struct Node *root, const string &s)
{
    int ch;
    bool flag = false;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
            flag = true;
        }
        temp = temp->child[ch];
        if (temp -> countWord > 0)
        {
            flag = false;
            break;
        }
    }
    for (int i = 0; i < MAX; i++) 
    {
        if (temp->child[i] != NULL) 
        {
            return false;
        }
    }
    temp->countWord = 1;
    return flag;
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
    struct Node *root = newNode();
    vector<string> setStr(n);
    for (int i=0; i<n; i++)
    {
        cin >> setStr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (addWord(root, setStr[i]) == false)
        {
            cout << "BAD SET" << endl;
            cout << setStr[i];
            deletenode(root);
            return 0;
        }
    }
    cout << "GOOD SET" << endl;
    deletenode(root);

    return 0;
}
