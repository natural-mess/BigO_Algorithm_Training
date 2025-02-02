#include <bits/stdc++.h>
using namespace std;

#define MAX 10

struct Node
{
    struct Node *child[MAX];
    int countDataset;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->countDataset = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

bool addNum (struct Node *root, const string &s)
{
    int ch;
    bool flag = false;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - '0';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
            flag = true;
        }
        temp = temp->child[ch];
        if (temp -> countDataset > 0)
        {
            flag = false;
            break;
        }
    }
    temp->countDataset = 1;
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
    int t, tc = 1;;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        struct Node *root = newNode();
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (addNum(root, s) == false)
            {
                flag = false;
            }
        }
        cout << "Case " << tc++ << ": " << (flag?"YES":"NO") << endl;
        deletenode(root);
    }


    return 0;
}
