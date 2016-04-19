//求最大公共子串，【动态规划】
int getLongestSubString(char* query,char* text){
	int imax = INT_MIN;
	int m = strlen(query);
	int n = strlen(text);
	vector<vector<int> > temp(m,vector<int>(n,0));//创建一个m行n列的全0二维数组
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(query[i]==text[j])
			{
				temp[i][j] = 1;
			}
			else
			{
				temp[i][j]=temp[i-1][j-1]+1;
			}
			
			imax = max(imax,temp[i][j]);
		}
	}
	
	return imax;
}
