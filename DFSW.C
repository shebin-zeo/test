#include <stdio.h>

#define MAX_VERTICES 20

int n, i, j, visited[MAX_VERTICES], stack[MAX_VERTICES], cost[MAX_VERTICES][MAX_VERTICES], x = 0;

void dfs(int);

int main() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the elements\n");
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            printf("\nposition(%d,%d)", i, j);
            scanf("%d", &cost[i][j]);
            cost[j][i] = cost[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    int cr;
    printf("\nEnter the starting vertex: ");
    scanf("%d", &cr);
    visited[cr] = 1;
   // printf("\nDFS Traversal: ");
   // printf("%d ", cr);
    stack[0] = cr;
    dfs(cr);

    return 0;
}

void dfs(int cr) {
    int top = 0;
    int popped[MAX_VERTICES]; // To store popped elements for printing later
    int p = 0; // Index for storing popped elements
    while (top >= 0) {
        int current = stack[top];
        int found = 0;
        for (i = 0; i < n; i++) {
            if (cost[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
               // printf("%d ", i);
                stack[++top] = i;
                found = 1;
                break;
            }
        }
        if (!found) {
            popped[p++] = stack[top]; // Store popped element
            top--;
        }
    }

    printf("\nPopping Order from Stack: ");
    for (i = p - 1; i >= 0; i--) {
        printf("%d ", popped[i]); // Print elements in popping order
    }
}