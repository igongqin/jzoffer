#include <iostream>
#include <vector>
using namespace std;

 typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
	//  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  }TreeNode;

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
		if(pre.empty()==true||in.empty()== true)
			return NULL;
		return ConstructCore(pre.begin(),pre.end()-1,in.begin(),in.end()-1);
    }
	TreeNode* ConstructCore(vector<int>::iterator startpre,vector<int>::iterator endpre,vector<int>::iterator startin,vector<int>::iterator endin)
	{
		int rootValue=*startpre;
	//	cout<<rootValue<<endl;
		TreeNode* root=new TreeNode();
		root->val=rootValue;
		root->left=root->right=NULL;

		if(startpre == endpre)
		{
			if(startin==endin && *startpre == *startin)
				return root;
			else
				throw "Invalid input.";

		}

		vector<int>::iterator rootInorder = startin;
		while(rootInorder <= endin && *rootInorder != rootValue)
			++ rootInorder;
		if(rootInorder == endin && *rootInorder != rootValue)
			throw "Invalid input.";


		int leftLength = rootInorder - startin;
		vector<int>::iterator leftPreend = startpre + leftLength;
		if(leftLength > 0)
		{
			root->left=ConstructCore(startpre+1,leftPreend,startin,rootInorder-1);
		}
		if(leftLength<endpre-startpre)
		{
			root->right=ConstructCore(leftPreend+1,endpre,rootInorder+1,endin);
		}
		return root;
	}
};

void main()
{
	int a[]={1,2,4,7,3,5,6,8};
	int b[]={4,7,2,1,5,3,8,6};
	vector<int> pre;
	vector<int> in;
	//cout<<sizeof(a)<<endl;       32
	for(int i=0;i<8;i++)
	{
		pre.push_back(a[i]);
		in.push_back(b[i]);
	}

	Solution ss;
	ss.reConstructBinaryTree(pre,in);

	system("pause");
    return ;
}
