// # Robot Challenge
//
// ## Description
//
// There is an n x m map, and the goal of the robot Coco is to start from the position 'S' and reach
// the destination 'E' Robot Coco can move up, down, left, or right, and can only move one grid at a
// time. Write a program to calculate the minimum number of moves required for robot Coco to move
// from S to E.
//
// ## Input
//
// There are two lines of input. The first line contains two integers, n and m, representing themap.
// The following n lines contain m integers each, either 0 or 1, where 1 represents an obstaclethat
// cannot be passed and 0 represents a passable area. S represents the current positionof the robot,
// and E represents the target position.
//
// ## Constraints
//
//- 1<n,m<1000
//
// ## Output
//
// Output an integer that represents the minimum number of moves required for robot Coco to move
// from S to E.
//
// Please use a C++11!

#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000;
int n, m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Point
{
    int x, y;
};

int bfs(Point start, Point end)
{
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    dist[start.x][start.y] = 0;

    while (!q.empty())
    {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y)
        {
            return dist[curr.x][curr.y];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '1' && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[curr.x][curr.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    Point start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'S')
            {
                start.x = i;
                start.y = j;
            }
            else if (grid[i][j] == 'E')
            {
                end.x = i;
                end.y = j;
            }
        }
    }

    cout << bfs(start, end) << endl;

    return 0;
}
