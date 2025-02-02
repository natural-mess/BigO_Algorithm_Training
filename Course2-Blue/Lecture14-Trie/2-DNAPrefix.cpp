#include <bits/stdc++.h>
using namespace std;

#define MAX 4 // A, C, G, T
vector<char> dna = {'A', 'C', 'G', 'T'};
int res;
struct Node
{
    struct Node *child[MAX];
    int countChar;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->countChar = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

void addWord (struct Node *root, const string &s)
{
    int ch, level;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = find(dna.begin(), dna.end(), s[i]) - dna.begin();
        level = i+1;
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        temp->countChar++;
        res = max(res, level*temp->countChar);
    }
    
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
        string s;
        res = 0;
        struct Node *DNAPrefix = newNode();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            addWord(DNAPrefix, s);
        }
        cout << "Case " << tc++ << ": " << res << endl;
    }

    return 0;
}