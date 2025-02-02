#include <bits/stdc++.h>
using namespace std;

#define MAX 26

struct Node
{
    struct Node *child[MAX];
};

struct Node *newNode()
{
    struct Node *node = new Node;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
}

void addWord(struct Node *root, const string &s, long long *endWith, long long &totalWord)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
            
            totalWord++;

            if (i > 0)
            {
                endWith[ch]++;
            }
            
        }
        temp = temp->child[ch];
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

int main()
{
    int p, s;
    long long pEndWith[26];
    long long sEndWith[26];
    long long pTotalWord;
    long long sTotalWord;
    while (1)
    {
        cin >> p >> s;
        if (p==0 && s==0)
        {
            break;
        }
        memset(pEndWith, 0, sizeof(pEndWith));
        memset(sEndWith, 0, sizeof(sEndWith));
        pTotalWord = 0;
        sTotalWord = 0;
        string pWords, sWords;
        struct Node *pTrie = newNode(), *sTrie = newNode();
        for (int i = 0; i < p; i++)
        {
            cin >> pWords;
            addWord(pTrie, pWords, pEndWith, pTotalWord);
        }
        for (int i = 0; i < s; i++)
        {
            cin >> sWords;
            reverse(sWords.begin(), sWords.end());
            addWord(sTrie, sWords, sEndWith, sTotalWord);
        }
        long long undif = 0;
        for (int i = 0; i < MAX; i++)
        {
            undif += 1LL * pEndWith[i] * sEndWith[i];
        }
        cout << (1LL * pTotalWord * sTotalWord) - undif << endl;
        deletenode(pTrie);
        deletenode(sTrie);
    }

    return 0;
}