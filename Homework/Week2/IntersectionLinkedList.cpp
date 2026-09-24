struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != nullptr || curB != nullptr) {
            if (curA == curB) {
                break;
            } else {
                if (curA == nullptr) {
                    curA = headB;
                    curB = curB->next;
                    continue;
                }
                if (curB == nullptr) {
                    curA = curA->next;
                    curB = headA;
                    continue;
                }
                curA = curA->next;
                curB = curB->next;
            }
        }
        return curA;
    }
};