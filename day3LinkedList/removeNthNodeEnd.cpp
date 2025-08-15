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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == NULL) return head->next;

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;

        // if(head == NULL && n <= 0){
        //     return head;
        // }

        // int count = 0;
        // ListNode * temp = head;

        // // find the len of the list Node 
        // while(temp != NULL){
        //     count++;
        //     temp = temp -> next;
        // }

        // int ans = count - n;
        
        // temp = head;
        // ListNode * prev = NULL;

        // int a = 0;

        // while(temp != NULL){
        //     if(a == ans){
        //         if(prev != NULL){
        //             prev -> next = temp -> next;
        //         }else{
        //             head = head -> next;
        //         }

        //         delete temp;
        //         return head;
        //     }

        //     prev  = temp;
        //     temp = temp -> next;
        //     a++;
        // }

        // return head;
    }
};

// Helper function to print the list
void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int n = 2;
    head = sol.removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
