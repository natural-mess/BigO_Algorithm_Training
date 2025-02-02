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

bool checkPrime(int x)
{
    bool ret;
    int count = 0;
    if (x==1)
    {
        ret = false;
    }
    else
    {
        for (int i=2; i<x; i++)
        {
            if (x%i==0)
            {
                count++;
            }
        }
        (count==0)? (ret = true) : (ret = false);
    }
    return ret;
}

int countPrimeLinkedList(LinkedList lst)
{
    if (lst.head == NULL)
    {
        return -1;
    }
    int count = 0;
    Node *cur = lst.head;
    while (cur!=NULL)
    {
        if (checkPrime(cur->data)==true)
        {
            count++;
        }
        cur = cur->next;
    }
    return count;
}

int main()
{
    LinkedList list;
    init(list);

    while (1)
    {
        int x;
        cin >> x;
        if (x==-1)
        {
            break;
        }
        insertTail(list, x);
    }
    cout << countPrimeLinkedList(list);
		removeAll(list);
    return 0;
}
