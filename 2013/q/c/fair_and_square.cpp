#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool is_palindrome(int i) {
	string s = to_string(i);
	int l = s.length();
	for(int x = 0; x < l; x++) {
		if(s[x] != s[l-1-x]) return false;
	}
	return true;
}
int main() {
	int T, c=0;
	cin >> T;
	while(c++<T) {
		long A,B,r=0;
		cin >> A >> B;
		for(int x = 1; x <= B; x++) {
			long y = pow(x,2);
			if(y > B) break;
			if(y < A) continue;
			if(is_palindrome(x) && is_palindrome(y)) r++;
		}
		cout << "Case #" << c << ": " << r << endl;
	}
}
/* 
 * too slow
 * ideally would write in haskell
 * also `long` is not large enough
 */
