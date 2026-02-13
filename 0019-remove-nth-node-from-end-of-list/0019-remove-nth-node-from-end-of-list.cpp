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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL && n == 1) 
            return NULL;

        ListNode* temp = head;
        int len = 0;

        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        if (n == len) 
            return head->next;

        temp = head;
        int c = 1;
        while (c < len - n) {
            temp = temp->next;
            c++;
        }

        temp->next = temp->next->next;

        return head;
    }
};
