

class Solution {
public:
    Node* copyRandomList(Node* head) {
     if(head==NULL)
        return NULL;
    Node* curr=head;
    
    while(curr!=NULL)
    {
        Node* dummy= new Node(curr->val);
        Node* next=curr->next;
        curr->next=dummy;
        dummy->next=next;
        curr=next;
    }
    curr= head;
    while(curr!=NULL)
    {
        curr->next->random=curr->random!=NULL?curr->random->next:NULL;
        curr=curr->next->next;
    }
    
    // step 3:-  detach orignal list and copy list;
    Node* orignal = head;
    Node* copy=head->next;
    Node* copy_head=head->next;
    while(orignal!=NULL & copy!=NULL)
    {
        orignal->next=orignal->next!=NULL?orignal->next->next:NULL;
        copy->next=copy->next!=NULL?copy->next->next:NULL;
        orignal=orignal->next;
        copy=copy->next;
    }
    return copy_head;   
    }
};