#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int findOverlappingPair(string s1, string s2, string& str)
{
	int max = INT_MIN;
	int m = s1.length();
	int n = s2.length();

	for (int i = 1; i <= min(m, n); i++)
	{
		if (s1.compare(m - i, i, s2, 0, i) == 0)
		{
			if (max < i)
			{
				max = i;
				str = s1 + s2.substr(i);
			}
		}
	}
	for (int i = 1; i <= min(m, n); i++)
	{
		if (s1.compare(0, i, s2, n - i, i) == 0)
		{
			if (max < i)
			{
				max = i;
				str = s2 + s1.substr(i);
			}
		}
	}

	return max;
}

string ShortestSuperstring(vector<string> arr)
{
	int n = arr.size();

	while (n != 1)
	{
		int max = INT_MIN;
		int p, q;
		string res_str;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				string str;

				int r = findOverlappingPair(arr[i], arr[j], str);
				if (max < r)
				{
					max = r;
					res_str.assign(str);
					p = i, q = j;
				}
			}
		}
		n--;
		if (max == INT_MIN)
			arr[0] += arr[n];
		else
		{
			arr[p] = res_str;
			arr[q] = arr[n];
		}
	}

	return arr[0];
}

int main()
{
	vector<string> arr = { "CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC" };

	cout << "The Shortest Superstring is " <<ShortestSuperstring(arr);

	return 0;
}

