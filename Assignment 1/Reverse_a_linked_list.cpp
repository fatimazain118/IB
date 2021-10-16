#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *reverse(node *&head)
{
    node *currptr = head;
    node *preptr = NULL;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next; 
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
    }
    return preptr;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 12);
    insertAtTail(head, 22);
    insertAtTail(head, 3);
    display(head);

    node *newhead = reverse(head);
    display(newhead);
    return 0;
}