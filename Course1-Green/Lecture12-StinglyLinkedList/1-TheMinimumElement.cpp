#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode (int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

struct LinkedList
{
    Node *head;
    Node *tail;
};

void init(LinkedList &list)
{
    list.head = NULL;
    list.tail = NULL;
}

void insertTail (LinkedList &lst, int x)
{
    Node *p = createNode(x);
    if (lst.head == NULL)
    {
        lst.head = lst.tail = p;
    }
    else
    {
        lst.tail->next = p;
        lst.tail = p;
    }
}

Node *min(LinkedList lst)
{
    if (lst.head == NULL)
    {
        return NULL;
    }
    Node *ans = lst.head;
    Node *cur = lst.head;
    while (cur!=NULL)
    {
        if (cur->data < ans->data)
        {
            ans = cur;
        }
        cur = cur->next;
    }
    return ans;
}

void removeAll (LinkedList &lst)
{
    while (lst.head != NULL)
    {
        Node *cur = lst.head;
        lst.head = lst.head->next;
        delete cur;
    }
    lst.tail = NULL;
}

int main()
{
    LinkedList list;
    init(list);

    while (1)
    {
        int x;
        cin >> x;
        if (x==0)
        {
            break;
        }
        insertTail(list, x);
    }
    Node *ans = min(list);
    cout << ans->data;

    return 0;
}
