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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* dummy = new ListNode(0);

        // Pointer used to build the result list
        ListNode* curr = dummy;

        // Stores carry from previous addition
        int carry = 0;

        // Continue while either list has nodes or carry remains
        while (l1 != nullptr || l2 != nullptr || carry) {

            // Get current value from l1, or 0 if l1 is exhausted
            int x = (l1 != nullptr) ? l1->val : 0;

            // Get current value from l2, or 0 if l2 is exhausted
            int y = (l2 != nullptr) ? l2->val : 0;

            // Add current digits and carry
            int sum = x + y + carry;

            // Update carry for next iteration
            carry = sum / 10;

            // Create a new node with the current digit
            curr->next = new ListNode(sum % 10);

            // Move to the newly created node
            curr = curr->next;

            // Advance l1 if possible
            if (l1)
                l1 = l1->next;

            // Advance l2 if possible
            if (l2)
                l2 = l2->next;
        }

        // Skip the dummy node and return the actual result
        return dummy->next;
    }
};