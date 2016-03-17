#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void ReplaceBlank(char *str,int length) {

		if(str==NULL || length <= 0)
			return ;

		int originalLength=0;
		int numberOfBlank=0;
		int i=0;
		while(str[i]!='\0')
		{
			++ originalLength;
			if(str[i]==' ')
				++ numberOfBlank;
			++ i;
		}

		int newLength = originalLength + numberOfBlank * 2;
		if (newLength > length)
			return ;
		int indexOfOriginal=originalLength;
		int indexOfNew=newLength;
		while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal )
		{
			if(str[indexOfOriginal] == ' ')
			{
				str[indexOfNew --]= '0';
				str[indexOfNew --]= '2';
				str[indexOfNew --]= '%';
			}
			else
			{
				str[indexOfNew --]=str[indexOfOriginal];
			}
			-- indexOfOriginal;
		}
		for(int j=0;j<newLength;j++)
		{
		cout << str[j] ;
		}
    }
};

void main()
{
	
	char aa[]="We are happy.";

	for(int j=0;j<strlen(aa);j++)
	{
		cout << aa[j] ;
	}
	cout<<endl;

	Solution ss;
	ss.ReplaceBlank(aa,20);

	system("pause");
	return ;
}
