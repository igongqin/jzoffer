#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        size_t len = rotateArray.size();
    if(len == 0)
        return 0;
    if(len == 1)
        return rotateArray[0];
    vector<int>::iterator low = rotateArray.begin();
    vector<int>::iterator mid;
    vector<int>::iterator high = rotateArray.end()-1;
    while(low <= high)
    {
        //防止迭代器失效
        mid = low + (high - low)/2;

        if(*mid >*high)//与尾部指针相比
        {
            low = mid + 1;
        }
        else if(*mid < *high)
        {
            high = mid;
        }
        else
        {
            high = high-1;
        }
        if(low >= high)
        {
            break;
        }
    }
        return *low;
    }

};

void main()
{
	int a[]={2,2,1,2,2,2};
	vector<int> aa;
	for(int i=0;i<5;i++)
	{
		aa.push_back(a[i]);
	}

	Solution ss;
	int b=ss.minNumberInRotateArray(aa);
	cout<<b<<endl;

	system("pause");
    return ;
}
