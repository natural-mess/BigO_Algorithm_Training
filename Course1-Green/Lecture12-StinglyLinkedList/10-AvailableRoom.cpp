#include <bits/stdc++.h>
using namespace std;

struct Node {
    string room;
    int price;
    int availability;
    Node* next;
};

Node* createNode (string room, int price, int availability)
{
    Node *p = new Node;
    p->room = room;
    p->price = price;
    p->availability = availability;
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

void insertTail (LinkedList &lst, string room, int price, int availability)
{
    Node *p = createNode(room, price, availability);
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


void availableRoom (LinkedList lst)
{
    if (lst.head == NULL)
    {
        return;
    }
    Node *cur = lst.head;
    while (cur!=NULL)
    {
        if (cur->availability < 1)
        {
            cout << cur->room << " " << cur->price << endl;
        }
        cur = cur->next;
    }
    
}


int main()
{
    LinkedList list;
    init(list);
    int n;
    cin >> n;
    while (n>0)
    {
        string room;
        int price, availability;
        cin >> room >> price >> availability;
        insertTail(list, room, price, availability);
        n--;
    }
    availableRoom(list);

    removeAll(list);
    return 0;
}
