#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, c=0;
	cin >> N;
	while(c++ < N) {
		int I,C;
		cin >> C >> I;
		vector<int> vP;
		while(I-->0) {
			int P;
			cin >> P;
			vP.push_back(P);
		}
		bool done = false;
		for(int x = 0; !done && x < vP.size(); x++) {
			for(int y = x+1; y < vP.size(); y++) {
				if(vP[x] + vP[y] == C) {
					cout << "CASE #" << c << ": " << x+1 << " " << y+1 << endl;
					done = true;
					break;
				}
			}
		}
	}
}
