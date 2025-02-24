#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Directions: Up, Right, Down, Left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Node structure to store position and distance
typedef struct {
    int x, y, dist;
} Node;

// Queue structure for BFS
typedef struct {
    Node queue[ROW * COL];
    int front, rear;
} Queue;

// Enqueue operation
void enqueue(Queue *q, int x, int y, int dist) {
    q->queue[q->rear++] = (Node){x, y, dist};
}

// Dequeue operation
Node dequeue(Queue *q) {
    return q->queue[q->front++];
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// BFS Algorithm
int BFS(char maze[ROW][COL], int startX, int startY, int endX, int endY) {
    int visited[ROW][COL] = {0};
    Queue q = {.front = 0, .rear = 0};

    enqueue(&q, startX, startY, 0);
    visited[startX][startY] = 1;

    while (!isEmpty(&q)) {
        Node current = dequeue(&q);

        // Check if we've reached the end
        if (current.x == endX && current.y == endY) {
            return current.dist;  // Shortest path length
        }

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // Check maze boundaries and valid paths
            if (newX >= 0 && newX < ROW && newY >= 0 && newY < COL &&
                (maze[newX][newY] == '0' || maze[newX][newY] == 'E') && !visited[newX][newY]) {

                enqueue(&q, newX, newY, current.dist + 1);
                visited[newX][newY] = 1;
            }
        }
    }
    return -1;  // No path found
}

int main() {
    char maze[ROW][COL] = {
       //input
    };

    int startX, startY, endX, endY;

    // Locate Start (S) and End (E) positions
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (maze[i][j] == 'E') {
                endX = i;
                endY = j;
            }
        }
    }

    int result = BFS(maze, startX, startY, endX, endY);
    if (result != -1)
        printf("Shortest path length is: %d\n", result);
    else
        printf("No path exists.\n");

    return 0;
}