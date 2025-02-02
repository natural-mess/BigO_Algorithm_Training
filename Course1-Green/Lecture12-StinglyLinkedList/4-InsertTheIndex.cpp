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

void insertTheIndex(LinkedList lst)
{
    if (lst.head == NULL)
    {
        return ;
    }
    int count = 1;
    Node *cur = lst.head;
    while (cur!=NULL)
    {
        cout << count << " " << cur->data << " ";
        cur = cur->next;
        count++;
    }
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
    insertTheIndex(list);
    
    return 0;
}
