#include <iostream>
using namespace std;

#define N 8  // size of the maze

// Function to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// Check if maze[x][y] is safe to visit and not already visited
bool isSafe(int maze[N][N], int x, int y, bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && !visited[x][y]);
}

// Backtracking utility to explore all 4 directions
bool solveMazeUtil(int maze[N][N], int x, int y,
                   int sol[N][N], bool visited[N][N]) {
    // If destination is reached
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, visited)) {
        visited[x][y] = true;
        sol[x][y] = 1;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y, sol, visited)) return true;

        // Move Right
        if (solveMazeUtil(maze, x, y + 1, sol, visited)) return true;

        // Move Up
        if (solveMazeUtil(maze, x - 1, y, sol, visited)) return true;

        // Move Left
        if (solveMazeUtil(maze, x, y - 1, sol, visited)) return true;

        // Backtrack
        sol[x][y] = 0;
        visited[x][y] = false;
    }

    return false;
}

void solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};
    bool visited[N][N] = {false};

    if (!solveMazeUtil(maze, 0, 0, sol, visited)) {
        cout << "No solution exists\n";
        return;
    }

    cout << "Path found (4 directions):\n";
    printSolution(sol);
}

int main() {
    int maze[8][8] = {
        {1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1}
    };


    solveMaze(maze);
    return 0;
}