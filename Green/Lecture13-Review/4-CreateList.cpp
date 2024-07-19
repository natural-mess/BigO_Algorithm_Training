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

void createList(LinkedList lst)
{
    if (lst.head == NULL)
    {
        return;
    }
    LinkedList result;
    init(result);
    insertTail(result, lst.head->data);
    Node *cur1 = lst.head;
    Node *cur2 = lst.head->next;
    Node *cur3 = result.head;
    int x;
    while (cur2!=NULL)
    {
        x = cur1->data + cur2->data;
        Node *sum = createNode(x);
        sum->next = NULL;
        cur3->next = sum;
        // delete sum;
        cur1 = cur1->next;
        cur2 = cur2->next;
        cur3 = cur3->next;
    }
    Node *cur = result.head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main()
{
    LinkedList list;
    init(list);
    int n;
    cin>>n;
    int count = n;
    while (count>0)
    {
        int x;
        cin >> x;
        insertTail(list, x);
        count--;
    }
    createList(list);
    removeAll(list);
    return 0;
}