#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const long long int MAX_VALUE = 9999999;
struct NodeWeight {
    int dstNode;
    int weight;
};

class State {
public:
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;
    State(int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
};

struct cmp1 {
    bool operator () (const State& a, const State& b)
    {
        return a.distFromStart > b.distFromStart;
    }
};

class Solution {
public:
    static int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<NodeWeight>> graph(n + 1, vector<NodeWeight>(n + 1));
        // 构造图
        for (auto edge : times) {
            struct NodeWeight node;
            int from = edge[0];
            node.dstNode = edge[1];
            node.weight = edge[2];
            graph[from].push_back(node);
        }
        vector<int> distTo = dijkstra(k, graph);
        // 找到最长的那一条最短路径
        int res = 0;
        for (unsigned int i = 1; i < distTo.size(); i++) {
            if (distTo[i] == MAX_VALUE) {
                return -1;
            }
            res = std::max(res, distTo[i]);
        }
        return res;
    }
    static vector<int> dijkstra(int start, vector<vector<NodeWeight>> graph) {
        // distTo[i]的值就是起点start到i的最短路径权重
        vector<int> distTo(graph.size(), MAX_VALUE);
        // base
        distTo[start] = 0;
        // 优先级队列，distFromStart小的排在前面
        priority_queue<State, vector<State>, cmp1> pq;
        // 从起点start开始BFS
        pq.push(State(start, 0));
        while (!pq.empty()) {
            State curState = pq.top();
            int curNodeId = curState.id;
            int curDistFromStart = curState.distFromStart;
            if (curDistFromStart > distTo[curNodeId]) {
                continue;
            }
            // 将curNode相邻节点入队
            for (auto neighbor : graph[curNodeId]) {
                int nextNodeId = neighbor.dstNode;
                int distToNextNode = distTo[curNodeId] + neighbor.weight;
                // 更新dp table
                if (distTo[nextNodeId] > distToNextNode) {
                    distTo[nextNodeId] = distToNextNode;
                    pq.push(State(nextNodeId, distToNextNode));
                }
            }
        }
        return distTo;
    }
};

int main()
{
    vector<vector<int>> times(3, vector<int>(3));
    times[0][0] = 2;
    times[0][1] = 1;
    times[0][2] = 1;
    times[1][0] = 2;
    times[1][1] = 3;
    times[1][2] = 1;
    times[2][0] = 3;
    times[2][1] = 4;
    times[2][2] = 1;
    int dest = Solution::networkDelayTime(times, 4, 2);
    cout << dest << endl;
}