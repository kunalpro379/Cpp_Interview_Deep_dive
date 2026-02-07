struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* ReverseList(ListNode* second){
        ListNode* prev=nullptr;
        while(second){
            ListNode* next=second->next;
            second->next=prev;
            prev=second;
            second=next;
        }
        return prev;
        
    }
    ListNode* getMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&& fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)return ;
        ListNode* firstLL=head;
        //getMiddle
        ListNode* mid=getMiddle(head);
        //reverse second half;;
        ListNode* secondLL=ReverseList(mid->next);
        mid->next=nullptr;
        while(secondLL){
            ListNode* firstnext=firstLL->next;
            ListNode* secondnext=secondLL->next;
            firstLL->next=secondLL;
            secondLL->next=firstnext;
            firstLL=firstnext;
            secondLL=secondnext;
        }
    }
};