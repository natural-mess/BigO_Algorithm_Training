#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode (int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

struct LinkedList
{
    Node* head;
    Node* tail;
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

void intersectionLinkedLists (LinkedList list1, LinkedList list2)
{
    if (list1.head == NULL || list2.head == NULL)
    {
        cout << "NO INTERSECTION";
        return;
    }
    Node *cur1 = list1.head;
    Node *cur2 = list2.head;
    Node *curTemp1 = createNode(-1);
    Node *curTemp2 = createNode(-1);
    bool flag = false;
    while (cur1 != NULL && cur2 != NULL)
    {
        if ((cur1->data < cur2->data) || (curTemp1->data == cur1->data))
        {
            curTemp1 = cur1;
            cur1 = cur1->next;
        }
        else if ((cur2->data < cur1->data) || (curTemp2->data == cur2->data))
        {
            curTemp2 = cur2;
            cur2 = cur2->next;
        }
        else if (cur1->data == cur2->data)
        {
            flag = true;
            cout << cur1->data << " ";
            curTemp1 = cur1;
            curTemp2 = cur2;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
    }
    if (flag == false)
    {
        cout << "NO INTERSECTION";
    }
}

int main()
{
    LinkedList list1, list2;
    init(list1);
    init(list2);

    while (1)
    {
        int x;
        cin >> x;
        if (x==-1)
        {
            break;
        }
        insertTail(list1, x);
    }

    while (1)
    {
        int y;
        cin >> y;
        if (y==-1)
        {
            break;
        }
        insertTail(list2, y);
    }
    intersectionLinkedLists(list1, list2);

    removeAll(list1);
    removeAll(list2);
    return 0;
}
