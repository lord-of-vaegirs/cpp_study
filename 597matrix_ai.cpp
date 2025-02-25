#include <iostream>
#include <cstring>

#define MAXN 10
#define MAXQUEUE 10000 // 假设最大队列长度

struct Node {
    int x, y, steps;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    int n;
    std::cin >> n;
    
    int matrix[MAXN][MAXN];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    bool visited[MAXN][MAXN] = {false};
    Node queue[MAXQUEUE];
    int front = 0, rear = 0;
    
    // 初始化队列
    queue[0].x=0;
    queue[0].y=0;
    queue[0].steps=0;
    rear++; // Start from (1, 1) which is (0, 0) in 0-indexed
    visited[0][0] = true;
    
    while (front < rear) {
        Node current = queue[front++];
        
        if (current.x == n-1 && current.y == n-1) {
            // Reached the destination
            std::cout << current.steps << std::endl;
            return 0;
        }
        
        for (int i = 0; i < 4; ++i) {
            for (int step = 1; step <= matrix[current.x][current.y]; ++step) {
                int nx = current.x + dx[i] * step;
                int ny = current.y + dy[i] * step;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    queue[rear].x=nx;
                    queue[rear].y =ny;
                    queue[rear].steps=current.steps + 1;
                    rear++;
                }
            }
        }
    }
    
    return 0; // This line should never be reached if the input guarantees a solution
}
