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

// For a given depth x, find the maximum wordCount among all nodes at that depth
int query(Node* root, int x) 
{

    // We'll do a breadth-first search (BFS) on the Trie.
    queue<pair<Node*, int>> qu; // pair: (node, current depth)
    qu.push({root, 0});
    
    int maxCount = 0;
    while (!qu.empty()) 
    {
        auto [node, depth] = qu.front();
        qu.pop();
        
        // When we've reached depth x, update maxCount
        if (depth == x) 
        {
            maxCount = max(maxCount, node->wordCount);
        }
        // Otherwise, push all children (if depth < x)
        else if (depth < x) 
        {
            for (int i = 0; i < MAX; i++) 
            {
                if (node->child[i] != nullptr)
                    qu.push({node->child[i], depth + 1});
            }
        }
    }
    return maxCount;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        struct Node *root = newNode();
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            reverse(s.begin(), s.end());
            addWord(root, s);
        }
        int x;
        for (int i = 0; i < q; i++)
        {
            cin >> x;
            cout << query(root, x) << endl;
        }
        // Clean up the Trie memory after each test case
        deletenode(root);
        delete root;
        
    }
    return 0;
}