#include<iostream>
#include<vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
    public:
    ListNode* merge(vector<ListNode*>&lists){
        vector<int>vals;
        for(auto& list:lists){
            while(list){
                vals.push_back(list->val);
            }
        }
        sort(vals.begin(), vals.end());
        ListNode* head=vals[0];
        ListNode* curr=head;
        for(int i=1;i<vals.size();i++){
            // ListNode* curr=head;
            curr->next=new ListNode(vals[i]);
            curr=curr->next;
        }
        return head;

    }
};
//Optimized O(kn)
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a)return b;
        if(!b)return a;
        if(a->val<b->val){
            a->next=merge(a->next, b);
            return a;
        }
        else{
            b->next=merge(a, b->next);
            return b;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res=nullptr;
        for(auto list:lists){
            res=merge(res, list);
        }
        return res;
    }
};