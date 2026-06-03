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
    ListNode* removeZeroSumSublists(ListNode* head) {

        vector<int> arr;

        // Convert linked list to array
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        bool found = true;

        // Repeat until no zero sum subarray found
        while (found) {

            found = false;

            for (int i = 0; i < arr.size(); i++) {

                int sum = 0;

                for (int j = i; j < arr.size(); j++) {

                    sum += arr[j];

                    // Zero sum found
                    if (sum == 0) {

                        arr.erase(arr.begin() + i,
                                  arr.begin() + j + 1);

                        found = true;
                        break;
                    }
                }

                if (found) break;
            }
        }

        // Rebuild linked list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (int x : arr) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;
    }
};