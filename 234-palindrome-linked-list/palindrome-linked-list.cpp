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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow);
        // Step 3: Compare both halves
        ListNode* first = head;
        while (secondHalf) {
            if (first->val != secondHalf->val)
                return false;
            first = first->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};