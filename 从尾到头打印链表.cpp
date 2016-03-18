#include<iostream>
#include<vector>
using namespace std;

 typedef struct ListNode {
        int val;
        struct ListNode *next;
  }ListNode;

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) 
	{
        vector<int> a;
		printList(head,a);//递归的方式实现
		return a;
    }
	void printList(ListNode* head,vector<int> &a)
	{
		if(head!=NULL)
		{
			if(head->next!=NULL)
			{
				printList(head->next,a);				
			}
			a.push_back(head->val);
		}
	}
};

void main()
{

	ListNode *pHead=NULL;
	ListNode *r=(ListNode*)malloc(sizeof(ListNode));
	r->val=0;
	pHead=r;
	for(int i=1;i<5;i++) //单链表的创建
	{
		ListNode *q=(ListNode*)malloc(sizeof(ListNode));
		q->val=i;
		r->next=q;
		r=q;
	}
	r->next=NULL;

	ListNode *p=pHead;
	cout<<p->val<<" ";
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->val<<" ";
	}
	cout<<endl;

	Solution ss;
	vector<int> aa; 
	aa=ss.printListFromTailToHead(pHead);
	for (int i=0;i<aa.size();i++)
	{
		cout<<aa[i]<<" ";
	}
	cout<<endl;

	system("pause");
	return ;
}
