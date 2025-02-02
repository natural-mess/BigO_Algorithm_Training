#include <bits/stdc++.h>
using namespace std;

struct Node {
    double data;
    Node* next;
};

Node* createNode (double x)
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

void insertTail (LinkedList &lst, double x)
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

double secondLargestNumber (LinkedList lst)
{
    double max;
    if (lst.head == NULL)
    {
        return -1;
    }
    Node *cur = lst.head;
    max = cur->data;
    while (cur!=NULL)
    {
        if (cur->data > max)
        {
            max = cur->data;
        }
        cur = cur->next;
    }
    cur = lst.head;
    double secondMax = -1;
    while (cur!=NULL)
    {
        if ((cur->data > secondMax) && (cur->data < max))
        {
            secondMax = cur->data;
        }
        cur = cur->next;
    }
    return secondMax;
}

int main()
{
    LinkedList list;
    init(list);
    while (1)
    {
        double x;
        cin >> x;
        if (x==-1)
        {
            break;
        }
        insertTail(list, x);
    }
    cout << secondLargestNumber(list);

    removeAll(list);
    return 0;
}
