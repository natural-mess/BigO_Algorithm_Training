#include <bits/stdc++.h>
using namespace std;

struct Node {
    int day;
    int month;
    int year;
    Node* next;
};

Node* createNode (int day, int month, int year)
{
    Node *p = new Node;
    p->day = day;
    p->month = month;
    p->year = year;
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

void insertTail (LinkedList &lst, int day, int month, int year)
{
    Node *p = createNode(day, month, year);
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


void greatestDay (LinkedList lst)
{
    if (lst.head == NULL)
    {
        return;
    }
    Node *cur = lst.head;
    Node *max = lst.head;
    while (cur!=NULL)
    {
        if (cur->year > max->year)
        {
            max = cur;
        }
        else if (cur->year == max->year)
        {
            if (cur->month > max->month)
            {
                max = cur;
            }
            else if (cur->month == max->month)
            {
                if (cur->day > max->day)
                {
                    max = cur;
                }
            }
        }
        cur = cur->next;
    }
    cout << max->day << " " << max->month << " " << max->year;
}


int main()
{
    LinkedList list;
    init(list);
    int n;
    cin >> n;
    while (n>0)
    {
        int day, month, year;
        cin >> day >> month >> year;
        insertTail(list, day, month, year);
        n--;
    }
    greatestDay(list);
    removeAll(list);

    return 0;
}
