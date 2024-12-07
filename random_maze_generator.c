//미로찾기 응용버전 (랜덤 미로생성)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define N 10
#define M 10

int n = N;
int m = M;
int maze[N][M];
int visited[N][M];    // 방문한 곳 기록

// 방향 벡터 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 스택에 사용할 구조체 정의
typedef struct {
    int x, y;
} Point;

Point stack[MAX * MAX];
int sp = 0;

void push(int x, int y) {
    stack[sp].x = x;
    stack[sp].y = y;
    sp++;
}

Point pop() {
    sp--;
    Point p = {stack[sp].x, stack[sp].y};
    return p;
}

int is_empty() {
    return sp == 0;
}

// 경로를 출력
void print_path(Point end) {
    for (int i = 0; i < sp; i++) {
        printf("(%d, %d) ->", stack[i].x, stack[i].y);
        if ((i % 5) == 0) printf("\n");
    }
    printf(" goal\n");
}

// 스택을 이용한 미로 탐색
int miro() {
    push(0, 0);
    visited[0][0] = 1;

    while (!is_empty()) {
        Point current = pop();

        // 도착점에 도달한 경우
        if (current.x == n - 1 && current.y == m - 1) {
            print_path(current);
            return 1;
        }

        // 상,하,좌,우로 이동
        for (int i = 0; i < 4; i++) {
            // 다음 방문 후보지 결정
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // 다음 방문 후보지가 유효한 좌표인지, 방문하지 않았고, 이동할 수 있는지 확인 - push()
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1 && !visited[nx][ny]) {
                push(current.x, current.y);    // 현재 위치 저장
                push(nx, ny);
                visited[nx][ny] = 1;
                break; // 새로운 위치로 이동했으면 현재 반복문 종료
            }
        }
    }
    return 0;
}

// 미로를 출력
void print_maze() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// 방문지 출력
void print_visited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

// 벽 리스트 구조체 정의
typedef struct {
    int x, y;
} Wall;

Wall walls[N * M];
int wall_count = 0;

// 벽 리스트에 벽 추가
void add_wall(int x, int y) {
    walls[wall_count].x = x;
    walls[wall_count].y = y;
    wall_count++;
}

// 벽 리스트에서 무작위로 벽 선택
Wall remove_random_wall() {
    int index = rand() % wall_count;
    Wall wall = walls[index];
    walls[index] = walls[--wall_count];
    return wall;
}

// Prim's Algorithm을 사용한 무작위 미로 생성
void generate_random_maze() {
    srand(time(NULL));
    
    // 미로 초기화: 모두 벽으로 설정
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maze[i][j] = 0;
        }
    }

    // 시작점과 종료점 설정
    maze[0][0] = 1;
    maze[n-1][m-1] = 1;

    // 각 행에 최소 6개의 통로(1)를 무작위로 배치
    for (int i = 0; i < n; i++) {
        int count = 0;
        while (count < 7) {
            int j = rand() % m;
            if (maze[i][j] == 0) {
                maze[i][j] = 1;
                count++;
            }
        }
    }

    // 시작점에 인접한 벽 추가
    for (int i = 0; i < 4; i++) {
        int nx = 0 + dx[i];
        int ny = 0 + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
            add_wall(nx, ny);
        }
    }

    // 벽 리스트가 비어있지 않을 때까지 반복
    while (wall_count > 0) {
        Wall wall = remove_random_wall();
        int x = wall.x;
        int y = wall.y;

        // 벽의 두 방향 중 하나에 통로가 있는지 확인
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1) {
                count++;
            }
        }

        if (count == 1) {
            maze[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                    add_wall(nx, ny);
                }
            }
        }
    }

    // 미로가 제대로 연결되지 않는 경우를 방지하기 위해 모든 셀이 연결될 때까지 반복
    int connected = 0;
    while (!connected) {
        connected = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 1) {
                    int path_exists = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1) {
                            path_exists = 1;
                            break;
                        }
                    }
                    if (!path_exists) {
                        maze[i][j] = 0;
                        connected = 0;
                    }
                }
            }
        }
    }
}

int main() {
    // 무작위 미로 생성
    generate_random_maze();

    // 미로 출력
    print_maze();

    // 방문 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    // 미로 탐색
    if (!miro()) {
        printf("No\n");
    }

    // 방문지 출력
    print_visited();

    return 0;
}
