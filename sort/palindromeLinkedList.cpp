#include<iostream>
#include<string>

 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int printListNode(ListNode *node)
{
    ListNode *temp = node;
    while (temp != NULL){
        cout << temp->val << "   ";
        temp = temp->next;
    }
    return 0;
}

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL){
        return true;
    }

    ListNode* temp = head;
    ListNode* reverse = new ListNode(temp->val);

    while (temp != NULL){
        ListNode* reverse_next = new ListNode(temp->val);
        reverse_next->next = reverse;
        reverse = reverse_next;
        temp = temp-> next;
    }

    while(head != NULL && reverse != NULL){
        if (head->val != reverse->val){
            return false;
        }
        head = head->next;
        reverse = reverse->next;
    }

    return true;
}

int addNode(ListNode *lNode, int *arr, int len){
    if (arr == NULL){
        return 0;
    }

    // the first node
    if (!lNode){
        ListNode *node = new ListNode(arr[0]);
        lNode = node;
    }
    else{
        lNode->val = arr[0];
    }

    // add node 
    ListNode *temp = lNode;
    for (int i = 1; i < len; i++){
        ListNode *node = new ListNode(arr[i]);
        temp->next = node;
        temp = temp->next;
    }
    // the last node
    temp->next = NULL;
    cout << endl;
    return 1;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    ListNode *node;

    int len = sizeof(arr)/sizeof(arr[0]); 
    addNode(node, arr, len);
    printListNode(node);
    cout << endl;
    cout << isPalindrome(node) << endl;

    return 0;    
}