struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* cur = headA;
        while (cur != nullptr) {
            lenA += 1;
            cur = cur->next;
        }
        cur = headB;
        while (cur != nullptr) {
            lenB += 1;
            cur = cur->next;
        }
        ListNode* curA = headA;
        ListNode* curB = headB;
        if (lenA > lenB) {
            int cnt = lenA - lenB;
            while (cnt--) {
                curA = curA->next;
            }
        } else {
            int cnt = lenB - lenA;
            while (cnt--) {
                curB = curB->next;
            }
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};