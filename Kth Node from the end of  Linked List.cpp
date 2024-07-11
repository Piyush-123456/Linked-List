class Solution {
  public:
    int getLength(Node* head){
        Node* temp = head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    int getKthFromLast(Node *head, int k) {
        // Your code here
        if(!head) return 0;
        int n = getLength(head);
        if(k>n) return -1;
        int pos = n - k +1;
        Node* temp = head;
        while(pos!=1){
            pos--;
            temp = temp->next;
        }
        return temp->data;
    }
};
