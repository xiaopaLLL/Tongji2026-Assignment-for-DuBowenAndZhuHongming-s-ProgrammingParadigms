// 作业在https://github.com/xiaopaLLL/Tongji2026-Assignment-for-DuBowenAndZhuHongming-s-ProgrammingParadigms.git
// 开源 卑微人求个star，感谢

#include <iostream>
#include <queue>
#include <string>
#include <utility>  //pair所在头
#include <vector>

// 经典bfs
// 只需记录走过的路保证不重复走，最多遍历每个格子一次
// 若遍历结束仍未遍历到终点，则终点不可达
// 时间复杂度O(r*c)

int main() {
  // 4个方向
  const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

  int r, c;
  std::cin >> r >> c;
  std::vector<std::string> mp(r);  // 地图数组
  // 二维数组记录是否走过和距离
  std::vector<std::vector<bool>> visited(r, std::vector<bool>(c, false));
  std::vector<std::vector<int>> dist(r, std::vector<int>(c, -1));
  // bfs所需队列
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < r; i++) std::cin >> mp[i];

  // bfs搜索
  if (mp[0][0] == '0') {
    q.push({0, 0});
    dist[0][0] = 0;
    visited[0][0] = true;
  }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    // 四向拓展
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      bool can_visit = nx >= 0 && nx < r && ny >= 0 && ny < c &&
                       mp[nx][ny] == '0' && !visited[nx][ny];
      if (can_visit) {
        dist[nx][ny] = dist[x][y] + 1;
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }

  // 输出终点结果（-1为不可达）
  std::cout << dist[r - 1][c - 1] << std::endl;

  return 0;
}