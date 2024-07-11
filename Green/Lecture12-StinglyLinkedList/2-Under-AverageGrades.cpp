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

void underAverage(LinkedList lst)
{
    if (lst.head == NULL)
    {
        return;
    }
    LinkedList ans;
    init(ans);
    Node *cur = lst.head;
    while (cur!=NULL)
    {
        if (cur->data < 5.0)
        {
            insertTail(ans, cur->data);
        }
        cur = cur->next;
    }
    cur = ans.head;
    while (cur != NULL)
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
    removeAll(ans);
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
    underAverage(list);
    // Node* cur = ans.head;
    // while (cur != NULL)
    // {
    //     cout << cur->data;
    //     cur = cur->next;
    // }
    
    removeAll(list);
    // removeAll(ans);
    return 0;
}
