#include <cstdio>
#include <queue>
#include <cstring>

int n, l, x, y;
int edge[201][201], color[201];

inline bool is_bipartite() {
    std::queue<int> q;
    memset(color, -1, sizeof(color));
    color[0] = 1;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
	q.pop();
	for(int v=0; v<n; ++v) {
	    if(edge[u][v]!=1) continue;
	    if(color[v] == -1) {
	        color[v] = 1 - color[u];
		q.push(v);
	    } else if(color[u] == color[v]) {
	        return false;
	    }
	}
    }
    return true;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        if(n==0) break;
	scanf("%d", &l);
	memset(edge, 0, sizeof(edge));
	for(int i=0; i<l; ++i) {
	    scanf("%d %d", &x, &y);
	    edge[x][y] = 1;
	    edge[y][x] = 1;
	}
	printf(is_bipartite() ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }
}
