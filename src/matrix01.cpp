#include "matrix01.h"
#include <queue>
#include <limits>

// 模板类实现
template<typename T>
std::vector<std::vector<T>> Matrix01<T>::updateMatrix(const std::vector<std::vector<T>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    std::queue<std::pair<int,int>> q;

    std::vector<std::vector<T>> dist(m, std::vector<T>(n, std::numeric_limits<T>::max()));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto &d : dirs){
            int nx = x + d[0];
            int ny = y + d[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
               dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist;
}

// ⚠️ 显式实例化模板类（必须写，不然 main.cpp 会找不到实现）
template class Matrix01<int>;

