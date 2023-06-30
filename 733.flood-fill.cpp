class Solution
{
public:
    void bfs(int row, int col, int initial, vector<vector<int>> &vis, vector<vector<int>> &image)
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while (!q.empty())
        {
            cout << "y";
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == initial && vis[nrow][ncol] != 1)
                {
                    image[nrow][ncol] = image[row][col];
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = 0;
            }
        }
        if (image[sr][sc] != color)
        {
            int initial = image[sr][sc];
            image[sr][sc] = color;
            bfs(sr, sc, initial, vis, image);
        }
        return image;
    }
};