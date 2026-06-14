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
    ListNode* revrese(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next; 
            curr->next = prev;           
            prev = curr;                 
            curr = next;                
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        int sum =0;
        int maxx = INT_MIN;
        ListNode * second ; 
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp ->next;
        }
         n = n/2;
        second = head;
        while(n){
            second = second ->next;
            n--;
        }

        second = revrese(second);
        temp = head;
        while(second!=NULL){
            sum = temp->val + second->val;
            maxx = max(maxx , sum);
            temp = temp->next;
            second = second->next;
        }
        return maxx;
    }
};