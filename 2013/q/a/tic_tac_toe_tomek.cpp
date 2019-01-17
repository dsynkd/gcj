#include <iostream>
#include <string>
using namespace std;
int main() {
	const int s = 4;
	int N,c=0;
	char board[s][s];
	cin >> N;
	loop:
		if(c++>=N) return 0;
		// read position into matrix
		for(int x=0; x<s; x++) {
			string line;
			cin >> line;
			for(int y=0; y<s; y++) {
				board[x][y] = line[y];
			}
		}
		// iterate through matrix looking for winning positions
		// check lines
		for(int x=0; x<s; x++) {
			// either first or last row cell
			char ref = board[x][0] != 'T' ? board[x][0] : board[x][s-1];
			bool check = true;
			for(int y=0; y<s && check; y++) {
				if(board[x][y] != 'T' && board[x][y] != ref)
					check = false;
			}
			if(check && ref != '.') {
				cout << "Case #" << c << ": " << ref << " won" << endl;
				goto loop;
			}
		}
		// check columns
		for(int y=0; y<s; y++) {
			// either first or last column cell
			char ref = board[0][y] != 'T' ? board[0][y] : board[s-1][y];
			bool check = true;
			for(int x=0; x<s && check; x++) {
				if(board[x][y] != 'T' && board[x][y] != ref)
					check = false;
			}
			if(check && ref != '.') {
				cout << "Case #" << c << ": " << ref << " won" << endl;
				goto loop;
			}
		}
		// check diagonals
		char ref = board[0][0] != 'T' ? board[0][0] : board[s-1][s-1];
		bool check = true;
		for(int x=0; x<s && check; x++) {
			if(board[x][x] != 'T' && board[x][x] != ref)
				check = false;
		}
		if(check && ref != '.') {
			cout << "Case #" << c << ": " << ref << " won" << endl;
			goto loop;
		}
		ref = board[0][s-1] != 'T' ? board[0][s-1] : board[s-1][0];
		check = true;
		for(int x=0; x<s && check; x++) {
			if(board[x][s-1-x] != 'T' && board[x][s-1-x] != ref)
				check = false;
		}
		if(check && ref != '.') {
			cout << "Case #" << c << ": " << ref << " won" << endl;
			goto loop;
		}
		// either draw or incomplete
		for(int x=0; x<s; x++)
			for(int y=0; y<s; y++)
				if(board[x][y] == '.') {
					cout << "Case #" << c << ": " << "Game has not completed" << endl;
					goto loop;
				}
		cout << "Case #" << c << ": " << "Draw" << endl;
		goto loop;
}
/* culprits:
 * what if the first cell is T
 * off by 1 when using const `s` to index
 */
