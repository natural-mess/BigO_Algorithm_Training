#include <bits/stdc++.h>
using namespace std;

#define MAX 2 // only 0 and 1

vector<string> res;

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

bool addWord (struct Node *root, int level, int len, string s)
{
    if (level == len)
    {
        if (root->child[0] != NULL || root->child[1] != NULL)
        {
            return false;
        }
        root->countWord++;
        res.push_back(s);
        // cout << s << endl;
        return true;
    }
    for (int ch = 0; ch <= 1; ch++)
    {
        if (root->child[ch] == NULL)
        {
            root->child[ch] = newNode();
            if (addWord(root->child[ch], level+1, len, s + char(ch + 48)))
            {
                return true;
            }
        }
        else if (root->child[ch]->countWord == 0)
        {
            if (addWord(root->child[ch], level+1, len, s + char(ch + 48)))
            {
                return true;
            }
        }
    }
    return false;
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

void printWord(struct Node *root, const string &s)
{
    if (root == NULL)
    {
        return;
    }

    if (root->countWord)
    {
        cout << s << endl;
    }

    if (root->child[0] != NULL)
    {
        printWord(root->child[0], s + '0');
    }

    if (root->child[1] != NULL)
    {
        printWord(root->child[1], s + '1');
    }
}

int main()
{
    int n;
    cin >> n;
    int l;
    vector<int> wordInput(n);
    string s;
    struct Node *root = newNode();
    for (int i = 0; i < n; i++)
    {
        cin >> wordInput[i];
    }
    // sort(wordInput.begin(), wordInput.end());

    for (int i = 0; i < n; i++)
    {
        if (!addWord(root, 0, wordInput[i], ""))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    // printWord(root, "");
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }

    deletenode(root);

    return 0;
}
