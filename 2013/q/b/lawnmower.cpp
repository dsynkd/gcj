#include <iostream>
using namespace std;
int main() {
	int T,c=0;
	cin >> T;
	loop:
	if(c++>=T) return 0;
	int N,M;
	cin >> N >> M;
	int board[N][M];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> board[i][j];
	//if(c == 22) cout << N << ":" << M << endl;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			bool bX = true, bY = true;
			for(int x = 0; x < N; x++) {
				if(board[x][j] > board[i][j]) {
					bX = false;
					break;
				}
			}
			for(int y = 0; y < M; y++) {
				if(board[i][y] > board[i][j]) {
					bY = false;
					break;
				}
			}
			if(!bX && !bY) {
				cout << "Case #" << c << ": NO" << endl;
				goto loop;
			}
		}		
	}
	cout << "Case #" << c << ": YES" << endl;
	goto loop;
}
