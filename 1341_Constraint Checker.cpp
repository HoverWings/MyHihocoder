#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<cstring>
#include <map>

using namespace std;


map<char, int> mp;

string c[20];
bool used[26];

bool ok(int a, string &op, int b) 
{
	if (op == "<") return a<b;
	return a <= b;
}
// i is the 

int get_val(string &s, int &i) //get the val
{
	int res = 0;
	for (; s[i] && isdigit(s[i]) && !isalpha(s[i]); res *= 10, res += s[i++] - '0');
	if (isalpha(s[i])) res = mp[s[i++]];
	return res;
}

string get_op(string &s, int &i) //get the op
{
	string res;
	for (; s[i] && ispunct(s[i]); res += s[i++]); // ispunct()  punctuation
	return res;
}

bool check(int n) 
{
	int a, b;
	string op;
	for (int i = 0; i<n; i++) 
	{
		int j = 0;
		a = get_val(c[i], j);
		for (;;) 
		{
			op = get_op(c[i], j);
			if (op == "") break;
			b = get_val(c[i], j);
			if (!ok(a, op, b)) return false;
			a = b;
		}
	}
	return true;
}

int main()
{
	int n,T;
	cin >> n;
	for (int i = 0; i<n; i++) 
	{
		cin >> c[i];
		for (auto x : c[i])
			if (isalpha(x)) used[x - 'A'] = true;
	}
	int nv = 0;
	for (int i = 0; i<26; i++) nv += used[i];

	for (cin >> T; T--; ) // judge T formulas 
	{
		for (int i = 0; i<nv; i++) // so there need to proceed n times change
		{
			char x;
			int v;
			cin >> x >> v;
			mp[x] = v;
		}
		puts(check(n) ? "Yes" : "No");
	}
}
