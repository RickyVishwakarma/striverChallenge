#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if (l1) temp->next = l1;
        if (l2) temp->next = l2;

        return dummy.next;
    }
};


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
