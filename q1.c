#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
struct node
{
    int info;
    struct node *left, *right;
};
struct node *createnode(int key)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
static int count = 0;
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
int main()
{
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
    printf("Number of nodes in tree 1 = %d ",countnodes(newnode));
    printf("\n");
    count = 0;
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);
    printf("Number of nodes in tree 2 = %d ",countnodes(node));
    printf("\n");
    count = 0;
    struct node *root = createnode(15);
    printf("Number of nodes in tree 3 = %d/n",countnodes(root));
    return 0;
}
=======

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int in_degree[MAX];
int n; // Number of vertices

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

void topologicalSortDFS() {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
    printf("Topological Sort (DFS method): ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
void topologicalSortSourceRemoval() {
    int queue[MAX], front = 0, rear = -1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        in_degree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i]) {
                in_degree[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }
    printf("Topological Sort (Source Removal method): ");
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;
        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
    printf("\n");
    if (count != n) {
        printf("Graph has a cycle! Topological sorting not possible.\n");
    }
}

int main() {
    int edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSortDFS();
    topologicalSortSourceRemoval();
    return 0;
}
>>>>>>> 8614423 (message)
