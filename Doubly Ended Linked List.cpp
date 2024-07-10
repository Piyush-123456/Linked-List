#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Deleted Successfully" << endl;
    }
};

void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

int getLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void InsertAtSpecificPos(Node *&head, Node *&tail, int data, int pos)
{
    if (pos <= 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }
    int len = getLength(head);
    if (pos >= len)
    {
        InsertAtTail(head, tail, data);
        return;
    }
    else
    {
        Node *prevNode = NULL;
        Node *nextNode = head;
        while (pos != 1)
        {
            pos--;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        Node *newNode = new Node(data);
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
}

void DeleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "No Nodes to delete!" << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    if (pos <= 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    int len = getLength(head);
    if (pos == len)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {
        Node *prevNode = NULL;
        Node *nextNode = head;
        while (pos != 1)
        {
            pos--;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }
        prevNode->next = nextNode->next;
        nextNode->prev = NULL;
        nextNode->next->prev = prevNode;
        delete nextNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 4);
    InsertAtHead(head, tail, 1);
    PrintLL(head);

    cout << "Deleted Node: : " << endl;
    DeleteNode(head, tail, 2);
    PrintLL(head);
    return 0;
}
