#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        bool found=false;
    	int columns,rows;
   	 	rows=array.size();
    	columns=array[0].size();
        
    	if (array.empty()==false && columns>0 && rows>0)
        {
        int row=0;
        int column=columns-1;
        while(row<rows && column>0)
            {
            if(array[row][column] == target)
            {
				found=true;
            	break;
            }    
            else if(array[row][column] > target)
                -- column;
            else
                ++ row;
       		 }
  		  }
    	return found;
    }
};

void main()
{
	vector<int> a;
	vector<vector<int> > arr;
	int gq_arr[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	for(int m=0;m<4;m++)   //给二维vector赋值
	{
		for(int n=0;n<4;n++)
		{
			a.push_back(gq_arr[m][n]);
		}		
		arr.push_back(a);
		a.clear();
	}

	for(int i=0;i < arr.size();i++)    //输出二维数组
		{
			for(int j=0;j < arr[i].size();j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
	}

	Solution ss;
	bool last=ss.Find(arr,7);
	cout<<last<<endl;
	system("pause");
	return ;
}
