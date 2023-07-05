// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if the
// current arrangement is valid
bool adj_check(string s)
{
	for (int i = 0; i + 1 < s.size(); ++i)
		if (abs(s[i] - s[i + 1]) == 1)
			return true;
	return false;
}

// Function to rearrange the characters of
// the string such that no two neighbours
// in the English alphabets appear together
void Rearrange(string str)
{
	// To store the odd and the
	// even positioned characters
	string odd = "", even = "";

	// Traverse through the array
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] % 2 == 0)
			even += str[i];
		else
			odd += str[i];
	}

	// Sort both the strings
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	// Check possibilities
	if (!adj_check(odd + even))
		cout << odd + even;
	else if (!adj_check(even + odd))
		cout << even + odd;
	else
		cout << -1;
}

// Driver code
int main()
{
	string str = "AABCD";

	Rearrange(str);

	return 0;
}
