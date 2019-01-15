#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// whenever a new wire gets added, check in the list of previous wires. for each case where prev.wire.begin > curr.wire.begin && prev.wire.end < curr.wire.end || prev.wire.begin < curr.wire.begin && prev.wire.end > curr.wire.end, y++

int main(int argc, char** argv) {
	int t, c = 0;
	cin >> t;
	while(c++<t) {
		vector<vector<int> > wires;
		int n, y = 0;
		cin >> n;
		while(n-->0) {
			vector<int> curr_wire;
			int temp;
			cin >> temp;
			curr_wire.push_back(temp); // starting point
			cin >> temp;
			curr_wire.push_back(temp); // end point
			for(vector<int> prev_wire : wires) {
				if((prev_wire[0] > curr_wire[0] && prev_wire[1] < curr_wire[1]) || (prev_wire[0] < curr_wire[0] && prev_wire[1] > curr_wire[1]))
					y++;
			}
			wires.push_back(curr_wire);
		}
		cout << "Case #" << c << ": " << y << "\n";
	}
}
