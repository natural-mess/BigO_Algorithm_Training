#include <bits/stdc++.h>
using namespace std;

#define MAX 26
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

void addWord (struct Node *root, string s)
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
    }
    temp->countWord++;
}

bool findWord (Node *root, string s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
}

int main()
{
    int tc=1;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct Node *DNAPrefix = newNode();
        for (int i = 0; i < n; i++)
        {
            
        }
        
    }

    return 0;
}