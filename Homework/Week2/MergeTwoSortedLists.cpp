struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {};
};
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* ptr1 = list1;
            ListNode* ptr2 = list2;
            ListNode* head = nullptr;
            ListNode* tail = nullptr;
            while (ptr1 != nullptr || ptr2 != nullptr) {
                if (ptr1 == nullptr) {
                    if (head == nullptr) {
                        head = ptr2;
                    } else {
                        tail->next = ptr2;
                    }
                    break;
                } 
                if (ptr2 == nullptr) {
                    if (head == nullptr) {
                        head = ptr1;
                    } else {
                        tail->next = ptr1;
                    }
                    break;
                }
                int val1 = ptr1->val;
                int val2 = ptr2->val;
                if (val1 < val2) {
                    if (head == nullptr) {
                        head = ptr1;
                        tail = head;
                    } else {
                        tail->next = ptr1;
                        tail = tail->next;
                    }
                    ptr1 = ptr1->next;
                } else {
                    if (head == nullptr) {
                        head = ptr2;
                        tail = head;
                    } else {
                        tail->next = ptr2;
                        tail = tail->next;
                    }
                    ptr2 = ptr2->next;
                }
            }
            return head;
        }
};