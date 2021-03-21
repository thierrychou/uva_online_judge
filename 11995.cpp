#include <cstdio>
#include <queue>
#include <stack>

int n, cmd, x;
bool isStack, isQueue, isPQueue;

int main() {
    while(scanf("%d", &n)!=EOF) {
        std::stack<int> s;
	std::queue<int> q;
	std::priority_queue<int> pq;
	isStack = isQueue = isPQueue = true;
        while(n--) {
	    scanf("%d %d", &cmd, &x);
	    if(cmd==1) {
		if(isStack) {
	            s.push(x);
		}
		if(isQueue) {
	            q.push(x);
		}
		if(isPQueue) {
		    pq.push(x);
		}
	    } else if(cmd==2) {
		if(isStack) {
	            if(!s.empty() && s.top()==x) {
		        s.pop();
		    } else {
			isStack = false;
		    }
		}
		if(isQueue) {
		    if(!q.empty() && q.front()==x) {
			q.pop();
		    } else {
			isQueue = false;
		    }
		}
		if(isPQueue) {
	 	    if(!pq.empty() && pq.top()==x) {
			pq.pop();
		    } else {
		        isPQueue = false;
		    }
		}
	    }
	}
	if(isStack && !isQueue && !isPQueue) {
	    printf("stack\n");
	} else if(!isStack && isQueue && !isPQueue) {
	    printf("queue\n");
	} else if(!isStack && !isQueue && isPQueue) {
	    printf("priority queue\n");
	} else if(!isStack && !isQueue && !isPQueue) {
	    printf("impossible\n");
	} else {
	    printf("not sure\n");
	}
    }
}
