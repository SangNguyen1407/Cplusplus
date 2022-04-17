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

int addNode(ListNode *lNode, int val){
    if (lNode){
        return 0;
    }

    ListNode *node = new ListNode(val);
    lNode->next = node;

    return 1;
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

ListNode* deleteDuplicates(ListNode* head) {
    if (!head){
        return NULL;
    }
    ListNode *temp = head;
    ListNode *temp1;

    while (temp){
        if(!temp->next){
            break;
        }
        if (temp->val == temp->next->val){
            temp1 = temp->next;
            temp->next = temp1->next;
            delete(temp1);
            continue;
        }
        temp = temp->next;
    }
    return head;
}

int insertNode(ListNode *lNode, int pos, int num){
    if (!lNode){
        return 0;
    }

    int i = 0;
    ListNode *temp = lNode;
    ListNode *node = new ListNode(num);
    while (1){
        if (temp == NULL){
            temp = node;
            break;
        }
        if (i == pos){
            ListNode *temp1  = temp->next;
            temp->next = node;
            node->next = temp1;
            break;
        }
        temp = temp->next;
        i++;
    }

    return 1;
}

int main ()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 6, 9, 9, 9};
    ListNode *node;

    int len = sizeof(arr)/sizeof(arr[0]); 
    addNode(node, arr, len);

    printListNode(node);
    cout << endl;
    //insertNode(node, 3, 5);
    deleteDuplicates(node);
    printListNode(node);


    return 0;    
}
