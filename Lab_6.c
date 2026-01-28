#include <stdio.h>
#include <limits.h>

#define MAX 20

/* FRACTIONAL KNAPSACK */
void fractionalKnapsack() {
    int n, i, j;
    float weight[MAX], profit[MAX], ratio[MAX];
    float capacity, totalProfit = 0, temp;

    printf("Enter number of items (max 20): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%f %f", &profit[i], &weight[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
            }

    for (i = 0; i < n; i++)
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }

    printf("Maximum profit = %.2f\n", totalProfit);
}

/* JOB SEQUENCING */
typedef struct { int id, deadline, profit; } Job;

void jobSequencing() {
    int n, i, j, maxD = 0, totalProfit = 0;
    Job jobs[MAX];
    int slot[MAX];

    printf("Enter number of jobs (max 20): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Enter deadline and profit for job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > maxD) maxD = jobs[i].deadline;
    }

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (jobs[i].profit < jobs[j].profit) {
                Job t = jobs[i]; jobs[i] = jobs[j]; jobs[j] = t;
            }

    for (i = 0; i < maxD; i++) slot[i] = -1;

    for (i = 0; i < n; i++)
        for (j = jobs[i].deadline - 1; j >= 0; j--)
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }

    printf("Job sequence: ");
    for (i = 0; i < maxD; i++)
        if (slot[i] != -1) printf("J%d ", slot[i]);
    printf("\nTotal profit: %d\n", totalProfit);
}

/* KRUSKAL */
typedef struct { int u, v, weight; } Edge;

int findParent(int parent[], int i) {
    while (parent[i] != i) i = parent[i];
    return i;
}

void kruskal() {
    int n, e, i, j, count = 0, total = 0;
    Edge edges[MAX];
    int parent[MAX];

    printf("Enter vertices and edges (max 20): ");
    scanf("%d %d", &n, &e);

    for (i = 0; i < e; i++) {
        printf("Enter u v weight: ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    for (i = 0; i < e - 1; i++)
        for (j = i + 1; j < e; j++)
            if (edges[i].weight > edges[j].weight) {
                Edge t = edges[i]; edges[i] = edges[j]; edges[j] = t;
            }

    for (i = 1; i <= n; i++) parent[i] = i;

    printf("Edges in MST:\n");
    for (i = 0; i < e && count < n - 1; i++) {
        int u = findParent(parent, edges[i].u);
        int v = findParent(parent, edges[i].v);
        if (u != v) {
            printf("%d - %d = %d\n", edges[i].u, edges[i].v, edges[i].weight);
            total += edges[i].weight;
            parent[u] = v;
            count++;
        }
    }
    printf("Total weight: %d\n", total);
}

/* PRIM */
void prim() {
    int n, i, j, e, min, x, y, total = 0;
    int g[MAX][MAX], sel[MAX];

    printf("Enter number of vertices (max 20): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for (i = 0; i < n; i++) sel[i] = 0;
    sel[0] = 1;

    printf("Edges in MST:\n");
    for (e = 0; e < n - 1; e++) {
        min = INT_MAX; x = y = -1;
        for (i = 0; i < n; i++)
            if (sel[i])
                for (j = 0; j < n; j++)
                    if (!sel[j] && g[i][j] && g[i][j] < min) {
                        min = g[i][j]; x = i; y = j;
                    }
        printf("%d - %d = %d\n", x, y, min);
        total += min;
        sel[y] = 1;
    }
    printf("Total weight: %d\n", total);
}

/* DIJKSTRA */
void dijkstra() {
    int n, i, j, c, src, u, min;
    int g[MAX][MAX], d[MAX], v[MAX];

    printf("Enter number of vertices (max 20): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter source: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) { d[i] = INT_MAX; v[i] = 0; }
    d[src] = 0;

    for (c = 0; c < n - 1; c++) {
        min = INT_MAX; u = -1;
        for (i = 0; i < n; i++)
            if (!v[i] && d[i] < min) { min = d[i]; u = i; }

        v[u] = 1;
        for (i = 0; i < n; i++)
            if (!v[i] && g[u][i] && d[u] + g[u][i] < d[i])
                d[i] = d[u] + g[u][i];
    }

    printf("Vertex  Distance\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, d[i]);
}

/* MAIN */
int main() {
    int ch;
    do {
        printf("\n1.Knapsack \n2.Job \n3.Kruskal \n4.Prim \n5.Dijkstra \n0.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) fractionalKnapsack();
        else if (ch == 2) jobSequencing();
        else if (ch == 3) kruskal();
        else if (ch == 4) prim();
        else if (ch == 5) dijkstra();
    } while (ch != 0);
    return 0;
}
