#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// time to int
int ttoi(string s) {
	int h = stoi(s.substr(0,s.find(':')));
	int m = stoi(s.substr(s.find(':')+1,s.length()));
	return h*60+m; 
}

int main() {
	int c=0,n;
	cin >> n;
	while(c++<n) {
		// n = number of trips, c = counter for loops since we cant use n as we are using them to calculate results
		int t,na,nb,nac=0,nbc=0;
		cin >> t >> na >> nb;
		vector<pair<int,int>> a,b,b2;
		string t1,t2;
		// add timetable pair values to A
		while(nac++<na) {
			cin >> t1 >> t2;
			a.push_back(pair<int,int>(ttoi(t1), ttoi(t2)));
		}
		// sort needed in order to find the earliest fitting round trip rather than just any round trip (greedy)
		sort(a.begin(), a.end());
		// add timetable pair values to B
		while(nbc++<nb) {
			cin >> t1 >> t2;
			b.push_back(pair<int,int>(ttoi(t1), ttoi(t2)));
			// b2 for backup since we will choose to erase members from B to prevent them from being considered in future iterations over A
			b2.push_back(pair<int,int>(ttoi(t1), ttoi(t2)));
		}
		sort(b.begin(), b.end());
		sort(b2.begin(), b2.end());
		// loop through pairs from A, loop through pairs from B, result.A-- and remove pair from B if there is a pair in B whose start time is earlier than current As end time + turnaround time
		for(int x = 0; x < a.size(); x++) {
			for(int y = 0; y < b.size(); y++) {
				if(b[y].second + t <= a[x].first) {
					na--;
					b.erase(b.begin() + y);
					break;
				}
			}
		}
		// repeat for B
		for(int x = 0; x < b2.size(); x++) {
			for(int y = 0; y < a.size(); y++) {
				if(a[y].second + t <= b2[x].first) {
					nb--;
					a.erase(a.begin() + y);
					break;
				}
			}
		}
		cout << "Case #" << c << ": " << na << " " << nb << endl;
	}
	return 0;
}
