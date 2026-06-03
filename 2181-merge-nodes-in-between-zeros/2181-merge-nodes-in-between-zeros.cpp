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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy =new ListNode();
        ListNode* curr = dummy;
        
        ListNode* temp = head->next;
        long long sum = 0;
        while(temp!=NULL){
            if(temp->val == 0){
                ListNode* newnode = new ListNode(sum);
                curr->next = newnode;
                curr = curr->next;
                sum=0;
            }else{
                sum=sum+temp->val;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};