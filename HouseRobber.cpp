#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) 
{
    int n = nums.size();
    if(nums.empty())
    {
        return 0;
    }
    int r1 = 0,r2 = nums[0];
    for(int i=1;i<n;i++)
    {
        r1 = max(r1 + nums[i],r2);
        swap(r1,r2);
    }
    return r2;
}
int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		nums.push_back(val);
	}
	cout << rob(nums);
	return 0;
}
