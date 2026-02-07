#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        return mid;
    }
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a)return b;
        if(!b)return a;
        if(a->val<b->val){
            a->next=merge(a->next, b);return a;
        }else{
            b->next=merge(a,b->next);return b;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* mid=getMid(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left, right);
    }
};