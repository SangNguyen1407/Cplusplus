#include<iostream>
#include<string.h>



#define NODEDATA_SIZE 200
#define OK            1
#define ERROR         0

static int test = 123;

struct Node
{
	char data[NODEDATA_SIZE];
	Node *next;
};
 
struct ListNode
{
	Node *head;
	Node *tail;
	int size;
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int nodeDataContructor(ListNode *list);
int printNodeData(ListNode *list);
int insertNode (ListNode *list, char *data);
int deleteNode (ListNode *list, char *findData);
int insertNode (ListNode *list, char *data, int pos);