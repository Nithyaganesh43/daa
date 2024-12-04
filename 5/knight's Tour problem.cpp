#include <iostream>
#include <vector>
using namespace std;

bool isValidMove(int x, int y, int n, vector<vector<int>>& board) {
    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1;
}

bool solveKnightTour(int x, int y, int move, int n, vector<int>& dx, vector<int>& dy, vector<vector<int>>& board) {
    if (move == n * n) return true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValidMove(nx, ny, n, board)) {
            board[nx][ny] = move;
            if (solveKnightTour(nx, ny, move + 1, n, dx, dy, board)) return true;
            board[nx][ny] = -1;
        }
    }
    return false;
}

void knightTour(int n) {
    vector<vector<int>> board(n, vector<int>(n, -1));
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    board[0][0] = 0;
    if (solveKnightTour(0, 0, 1, n, dx, dy, board)) {
        for (auto row : board) {
            for (int cell : row) cout << cell << " ";
            cout << endl;
        }
    } else {
        cout << "No solution" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    knightTour(n);
    return 0;
}
