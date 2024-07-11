#include <bits/stdc++.h>
using namespace std;

int palindrome;

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

int reverseNumber (int x)
{
    if (x == 0)
    {
        return palindrome;
    }
    if (palindrome == 0)
    {
        palindrome = x%10;
    }
    else
    {
        palindrome = palindrome*10 + x%10;
    }
    return reverseNumber(x/10);
}

void palindromeLinkedlist (LinkedList lst)
{
    if (lst.head == NULL)
    {
        return;
    }
    Node *cur = lst.head;
    LinkedList ans;
    init(ans);
    int count = 0;
    while (cur!=NULL)
    {
        if (cur->data == reverseNumber(cur->data))
        {
            insertTail(ans, count);
        }
        palindrome = 0;
        count++;
        cur = cur->next;
    }
    cur = ans.head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
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
        int x;
        cin >> x;
        if (x==-1)
        {
            break;
        }
        insertTail(list, x);
    }
    palindromeLinkedlist(list);

    removeAll(list);

    // int x;
    // cin>>x;
    // cout << reverseNumber(x);

    return 0;
}
