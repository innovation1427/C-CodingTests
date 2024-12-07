//미로 찾기 (미로 만들기)

#include <stdio.h>

#define MAX 100
#define N 10
#define M 10

int n = N;
int m = M;
int maze[N][M] = {
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                    { 0, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
                    { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
                    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 1, 1, 1, 1, 0, 1, 1, 1, 0 },
                    { 0, 0, 0, 1, 0, 1, 1, 0, 1, 0 },
                    { 0, 0, 0, 1, 1, 1, 0, 0, 1, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
};
int visited[N][M];    //방문한 곳 기록

/*//방향 벡터(상, 하, 좌, 우 순서가 우선순위)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};*/

//방향 벡터 (우, 하, 상, 좌)
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

//스택에 사용할 구조체 정의
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
Point pop(){
    sp--;
    Point p = {stack[sp].x, stack[sp].y};
    return p;
}
int is_empty(){
    return sp == 0;
}

//경로를 출력
void print_path(Point end) {
    for (int i = 0; i < sp; i++) {
        printf("(%d, %d) ->", stack[i].x, stack[i].y);
        if((i % 5) == 0) printf("\n");
    }
    printf(" goal\n");
}

//스택을 이용한 미로 탐색
int miro() {
    push(0, 0);
    visited[0][0] = 1;

    while (!is_empty()) {
        Point current = pop();

        //도착점에 도달한 경우
        if (current.x == n -1 && current.y == m - 1) {
            print_path(current);
            return 1;
        }

        //상,하,좌,우로 이동
        for (int i = 0; i < 4; i++){
            //다음 방문 후보지 결정
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            //다음 방문 후보지가 유효한 좌표인지, 방문하지 않았고, 이동할 수 있는지 확인 - push()
            if (nx >= 0 && nx < n && ny < m && maze[nx][ny] == 1 && !visited[nx][ny]) {
                push(current.x, current.y);    //현재 위치 저장
                push(nx, ny);
                visited[nx][ny] = 1;
                break; //새로운 위치로 이동했으면 현재 반복문 종료
            }
        }
    }
    return 0;
}

//미로를 출력
void print_maze(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

//방문지 출력
void print_visited(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}
    

int main() {
    //입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    //미로 출력
    print_maze();

    if (!miro()){
        printf("No\n");
    }

    //방문지 출력
    print_visited();

    return 0;
}