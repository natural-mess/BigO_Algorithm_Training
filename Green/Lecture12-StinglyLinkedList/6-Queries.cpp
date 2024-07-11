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

void deleteHeadNode (LinkedList &lst)
{
    if (lst.head != NULL)
    {
        if (lst.head == lst.tail)
        {
            removeAll(lst);
        }
        else
        {
            Node *cur = lst.head;
            lst.head = lst.head->next;
            delete cur;
        }
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
        int command, x;
        cin >> command;
        if (command == 0)
        {
            deleteHeadNode(list);
        }
        else if (command == 1)
        {
            cin >> x;
            insertTail(list, x);
        }
        n--;
    }

    Node *cur = list.head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }

    removeAll(list);

    return 0;
}
