#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Destructor Called!" << endl;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlen(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertAtSpecificPos(Node *&head, Node *&tail, int data, int pos)
{
    int len = getlen(head);
    if (pos == 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }
    if (pos >= len)
    {
        InsertAtTail(head, tail, data);
        return;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (pos != 1)
        {
            pos--;
            prev = curr;
            curr = curr->next;
        }
        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = curr;
    }
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "No Nodes to delete!";
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
    }
    int len = getlen(head);
    if (pos >= len)
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (pos != 1)
        {
            pos--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 5);
    InsertAtSpecificPos(head, tail, 3, 3);
    printLL(head);
    cout << "Deletion" << endl;
    deleteNode(head, tail, 3);
    printLL(head);
    return 0;
}