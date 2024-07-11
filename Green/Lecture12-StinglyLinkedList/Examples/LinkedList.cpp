#include<bits/stdc++.h>
using namespace std;
int a[1002], n;
struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head;
};

void inputLinkedList(LinkedList &lst)
{
    lst.head = NULL;
    Node *cur = NULL;
    for (int i = 1; i <= n; ++i)
    {
        // Create node
        Node *p = new Node;
        p->data = a[i];
        p->next = NULL;

        // Add this element into LinkedList
        if (lst.head == NULL)
        {
            lst.head = p;
            cur = p;
        }
        else
        {
            cur->next = p;
            cur = p;
        }
    }
}

Node *minLinkedList(LinkedList lst)
{
    if (lst.head == NULL)
        return 0;
    Node *ans = lst.head;
    Node *cur = lst.head;

    while (cur != NULL)
    {
        if (cur->data < ans->data)
            ans = cur;
        cur = cur->next;
    }
    return ans;
}

int main()
{
    LinkedList lst;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    inputLinkedList(lst);
    Node *ans = minLinkedList(lst);
    cout << ans->data;
}