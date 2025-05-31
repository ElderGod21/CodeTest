#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited) {
        return (x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (maze[x][y] == 1);
    }

    void solve(vector<vector<int>>& maze, vector<string>& ans, int n, int x, int y, vector<vector<int>>& visited, string path) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, maze, visited)) {
            path.push_back('D');
            solve(maze, ans, n, newx, newy, visited, path);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, maze, visited)) {
            path.push_back('L');
            solve(maze, ans, n, newx, newy, visited, path);
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, maze, visited)) {
            path.push_back('R');
            solve(maze, ans, n, newx, newy, visited, path);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, maze, visited)) {
            path.push_back('U');
            solve(maze, ans, n, newx, newy, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0; // backtrack
    }

public:
    vector<string> findPath(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (maze[0][0] == 0) return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        solve(maze, ans, n, 0, 0, visited, path);
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {{1,0,1,0,0},{1,1,0,0,1},{0,1,1,0,0},{0,1,1,1,1},{0,1,1,0,1}};
    Solution obj;
    vector<string> paths = obj.findPath(maze);

    for (string path : paths) {
        cout << path << endl;
    }

    return 0;
}
