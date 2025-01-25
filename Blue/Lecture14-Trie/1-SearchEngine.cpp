#include <bits/stdc++.h>
using namespace std;

#define MAX 26
struct Node
{
    struct Node *child[MAX];
    int countWord;
    int weight;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->countWord = 0;
    node->weight = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

void addWord (struct Node *root, string s, int weight)
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
        temp->weight = max(temp->weight, weight);
    }
    temp->countWord++;
}

int findWord (Node *root, string s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            return -1;
        }
        temp = temp->child[ch];
    }
    return temp->weight;
}

int main()
{
    int n, q;
    string s;
    int weight;
    struct Node *searchEngine = newNode();
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> weight;
        addWord(searchEngine, s, weight);
    }
    
    for (int i = 0; i < q; i++)
    {
        cin >> s;
        cout << findWord(searchEngine, s) << endl;
        // cout << searchEngine->child[s[0]-'a']->weight << endl;
    }

    return 0;
}