#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <utility>

int nc, testcase;
int i,j, ttl, count, s;

inline int bfs(int r, const std::multimap<int, int>& edges,std::map<int, int>& nodes) {
    std::queue<int> q;
    q.push(r);
    nodes[r] = 0;
    while(!q.empty()) {
        int v = q.front();
	q.pop();
	std::pair<std::multimap<int, int>::const_iterator, std::multimap<int, int>::const_iterator> edge_it = edges.equal_range(v);
	for(std::multimap<int, int>::const_iterator it=edge_it.first; it!=edge_it.second; ++it) {
	    int j = it->second;
	    if(nodes[j] == -1) {
	    	nodes[j] = nodes[v] + 1;
		q.push(j);
	    }
	}
    }
    count = 0;
    for(std::map<int, int>::const_iterator node_it = nodes.begin(); node_it != nodes.end(); ++node_it) {
	if(node_it->second==-1 ||node_it->second>ttl) ++count;
    }
    return count;
}

int main() {
    testcase = 0;
    while(scanf("%d", &nc)!=EOF && nc!=0) {
	std::map<int, int>      nodes;
	std::multimap<int, int> edges;
        while(nc--) {
	    scanf("%d %d", &i, &j);
	    edges.insert(std::make_pair(i, j));
	    edges.insert(std::make_pair(j, i));
	    nodes.insert(std::make_pair(i, -1));
	    nodes.insert(std::make_pair(j, -1));
        }
	while(scanf("%d %d", &s, &ttl)) {
	    if(s==0 && ttl==0) break;
	    for(std::map<int, int>::iterator node_it = nodes.begin(); node_it != nodes.end(); ++node_it) {
	        node_it->second = -1;
	    }
	    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++testcase, bfs(s, edges, nodes), s, ttl);
	}
    }
}
