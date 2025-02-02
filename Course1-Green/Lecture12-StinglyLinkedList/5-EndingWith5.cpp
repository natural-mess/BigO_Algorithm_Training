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

void endingWith5(LinkedList lst)
{
    if (lst.head == NULL)
    {
        return ;
    }
    Node *cur = lst.head;
    while (cur!=NULL)
    {
        if ((cur->data > 0) && (cur->data % 10 != 5))
        {
            cout << cur->data << " ";
        }
        else if ((cur->data < 0) && (cur->data % 10 != -5))
        {
            cout << cur->data << " ";
        }
        cur = cur->next;
    }
}

int main()
{
    LinkedList list;
    init(list);
    int n;
    cin>>n;
    while (n>0)
    {
        int x;
        cin >> x;
        insertTail(list, x);
        n--;
    }
    endingWith5(list);
    removeAll(list);

    return 0;
}
