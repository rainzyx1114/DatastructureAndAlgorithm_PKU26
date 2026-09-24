struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* endOfFirstPart = HalfOfList(head);
        ListNode* tail = reverseList(endOfFirstPart); 
        ListNode* start = head;
        while (start != nullptr && tail != nullptr) {
            if (start->val != tail->val) {
                return false;
            }
            start = start->next;
            tail = tail->next;
        }
        return true;
    }
    ListNode* HalfOfList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(head != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};