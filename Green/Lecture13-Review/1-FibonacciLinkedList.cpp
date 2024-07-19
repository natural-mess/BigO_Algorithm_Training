#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int x)
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

void insertTail(LinkedList &lst, int x)
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

void removeAll(LinkedList &lst)
{
    while (lst.head != NULL)
    {
        Node *cur = lst.head;
        lst.head = lst.head->next;
        delete cur;
    }
    lst.tail = NULL;
}

void FibonacciLinkedList(LinkedList lst, int n)
{
    if (lst.head == NULL)
    {
        return;
    }
    Node *cur1 = lst.head;
    Node *cur2 = lst.head->next;
    int x;
    int count = 2;
    while (n > count)
    {
        x = (cur1->data + cur2->data)%1000007;
        Node *sum = createNode(x);
        sum->next = NULL;
        cur2->next = sum;
        count++;
        // delete sum;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    Node *cur = lst.head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    // delete cur, cur1, cur2;
}

int main()
{
    LinkedList list;
    init(list);
    int x, y, n;
    cin >> x >> y >> n;
    insertTail(list, x);
    insertTail(list, y);
    // insertTail(list, n);
    FibonacciLinkedList(list, n);
    removeAll(list);
    return 0;
}