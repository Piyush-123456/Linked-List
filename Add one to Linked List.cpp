class Solution
{
    public:
    Node* reverse_linked_list(Node*& head){
        Node* prev= NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        head = reverse_linked_list(head);
        Node* temp = head;
        int carry = 1;
        while(temp->next!=NULL){
            int totalsum = temp->data + carry;
            int digit = totalsum%10;
            carry = totalsum/10;
            temp->data = digit;
            temp = temp->next;
            if(carry==0){
                break;
            }
        }
        if(carry!=0){
            int totalsum = temp->data + carry;
            int digit = totalsum%10;
            carry = totalsum/10;
            temp->data = digit;
            temp = temp->next;
            if(carry!=0){
               Node* newNode = new Node(carry);
               temp = temp->next;
            }
        }
        head = reverse_linked_list(head);
        return head;
        // return head of list after adding one
    }
};
