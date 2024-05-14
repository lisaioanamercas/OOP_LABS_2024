#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

ifstream fin("input.in.txt");


//////////////////////////////////////////////////////////////////////
string tolow(string s)
{
	for (auto i = 0; i < s.size(); i++)
		if (s[i] >= 'A' and s[i] <= 'Z')
			s[i] += 32;
	return s;
}

class Comp { ////obiect functional -> daca nu o scriu asa o sa imi urateasca codul la declararea priprity queue
public:
	bool operator() (const pair<string, size_t>& a, const pair<string, size_t>& b) const {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};
//////////////////////////////////////////////////////////////////////

string prop;	
string delim = " ,?!.";

map<string, size_t> h;

priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Comp>  q;

int main()
{
	getline(fin, prop);
	fin.close();


	size_t  i = 0, j = 0;

	string aux;

	while (i != string::npos)
	{
		i = prop.find_first_of(delim, j);///
		++h[tolow(prop.substr(j, i - j))];///punem cuvantul in lowercase si il incrementam in map

		i = prop.find_first_not_of(delim, i);///Searches the string for the first character 
											//that does not match any of the characters specified in its arguments
		j = i;
	}

	/*for (auto it = h.begin(); it != h.end(); it++)
		cout << it->first << " " << it->second << '\n';
	*/

	for (auto it = h.begin(); it != h.end(); it++)
		q.push(make_pair(it->first, it->second));

	while (!q.empty()) {
		cout << q.top().first << " => " << q.top().second << std::endl;
		q.pop();
	}
	return 0;
}