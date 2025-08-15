#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        while (temp1 != temp2) {
             temp1 = temp1 -> next;
            temp2 = temp2 -> next;

            if(temp1 == temp2) return temp1;

            if(temp1 == NULL) temp1 = headA;
            if(temp2 == NULL) temp2 = headB;
        }
        return temp1; 
    }
};

int main() {
    
    ListNode* common = new ListNode(6);
    common->next = new ListNode(7);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common;

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection Node Value: " << intersection->val << endl;
    } else {
        cout << "No Intersection" << endl;
    }

    return 0;
}
