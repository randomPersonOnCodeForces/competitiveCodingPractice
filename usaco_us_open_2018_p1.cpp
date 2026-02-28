#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));
int main()
{
    // freopen("tttt.in", "r", stdin);
    // freopen("tttt.out", "w", stdout);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }
    int individual = 0, team = 0;
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] == board[i][2]) individual++;
        else if (board[i][0] == board[i][1]) team++;
        else if (board[i][0] == board[i][2]) team++;
        else if (board[i][1] == board[i][2]) team++;
        if (board[0][i] == board[1][i] == board[2][i]) individual++;
        else if (board[0][i] == board[1][i]) team++;
        else if (board[0][i] == board[2][i]) team++;
        else if (board[1][i] == board[2][i]) team++;
    }

    if (board[0][0] != board[0][1] || board[i][0] != board[i][2] || board[i][1] != board[i][2]) 
    {
        if (board[i][0] == board[i][1]) team++;
        if (board[i][0] == board[i][2]) team++;
        if (board[i][1] == board[i][2]) team++;
        if (board[0][i] == board[1][i] == board[2][i]) individual++;
        else if (board[0][i] == board[1][i]) team++;
        else if (board[0][i] == board[2][i]) team++;
        else if (board[1][i] == board[2][i]) team++;
    }

    if (board[0][0] == board[1][1] == board[2][2]) individual++;
    else if (board[2][2] == board[1][1]) team++;
    else if (board[2][2] == board[0][0]) team++;
    else if (board[1][1] == board[0][0]) team++;
    if (board[0][2] == board[1][1] == board[2][0]) individual++;
    else if (board[0][2] == board[1][1]) team++;
    else if (board[0][2] == board[2][0]) team++;
    else if (board[1][1] == board[2][0]) team++;
    cout << individual << '\n' << team << endl;
    return 0;
}