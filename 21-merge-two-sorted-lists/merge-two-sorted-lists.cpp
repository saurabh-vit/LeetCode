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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyHead = new ListNode(); // Dummy node to simplify result construction
    ListNode* current = dummyHead;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    return dummyHead->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
            head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& values) {
    ListNode* dummyHead = new ListNode();
    ListNode* current = dummyHead;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummyHead->next;   
}