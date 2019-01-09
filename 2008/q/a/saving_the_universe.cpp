#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	int c=0,n;
	cin >> n;
	while(c++<n) {
		int s,q;
		string line;
		cin >> s;
		getline(cin,line);
		vector<string> engine;
		map<string,int> search;
		while(s-->0) {
			getline(cin,line);
			engine.push_back(line);
			search[line] = 0;
		}
		cin >> q;
		getline(cin,line);
		int swaps = 0;
		while(q-->0) {
			getline(cin,line);
			if(search.count(line))
				search[line]++;
			bool swap = true;
			for(auto const& x : search)
				if(x.second == 0) {
					swap = false;
					break;
				}
			if(swap) {
				for(auto const& x : engine)
					if(!x.compare(line))
						search[x] = 1;
					else
						search[x] = 0;
				swaps++;
			}
		}
		cout << "Case #" << c << ": " << swaps << endl;
	}
	return 0;
}
