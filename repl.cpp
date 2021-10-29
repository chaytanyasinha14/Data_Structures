// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the LPS array
// for the given string S1
vector<int> computeLPS(string& s1)
{
	// Stores the longest proper prefix
	// and suffix for each character
	// in the string s1
	vector<int> lps(s1.length());
	int len = 0;

	// Set lps value 0 for the first
	// character of the string s1
	lps[0] = 0;

	int i = 1;

	// Iterate to fill the lps vector
	while (i < s1.length()) {
		if (s1[i] == s1[len]) {
			len = len + 1;
			lps[i] = len;
			i = i + 1;
		}
		else {

			// If there is no longest
			// proper prefix which is
			// suffix, then set lps[i] = 0
			if (len == 0) {
				lps[i] = 0;
				i = i + 1;
			}

			// Otherwise
			else
				len = lps[len - 1];
		}
	}

	return lps;
}

// Function to replace all the occurrences
// of the substring S1 to S2 in string S
void modifyString(string& s, string& s1,
				string& s2)
{
	vector<int> lps = computeLPS(s1);
	int i = 0;
	int j = 0;

	// Stores all the starting index
	// from character S1 occurs in S
	vector<int> found;

	// Iterate to find all starting
	// indexes and store all indices
	// in a vector found
	while (i < s.length()) {
		if (s[i] == s1[j]) {
			i = i + 1;
			j = j + 1;
		}

		// The string s1 occurence is
		// found and store it in found[]
		if (j == s1.length()) {
			found.push_back(i - j);
			j = lps[j - 1];
		}
		else if (i < s.length()
				&& s1[j] != s[i]) {
			if (j == 0)
				i = i + 1;
			else
				j = lps[j - 1];
		}
	}

	// Stores the resultant string
	string ans = "";
	int prev = 0;

	// Traverse the vector found[]
	for (int k = 0; k < found.size(); k++) {
		if (found[k] < prev)
			continue;
		ans.append(s.substr(prev, found[k] - prev));
		ans.append(s2);
		prev = found[k] + s1.size();
	}

	ans.append(s.substr(prev,
						s.length() - prev));

	// Print the resultant string
	cout << ans << endl;
}

// Driver Code
int main()
{
	string S = "geeksforgeeks";
	string S1 = "eek";
	string S2 = "ok";
	modifyString(S, S1, S2);

	return 0;
}
