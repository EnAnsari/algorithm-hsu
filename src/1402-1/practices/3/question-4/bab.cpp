#include <iostream>

using namespace std;

#define N 3

struct result {
    result() {
        for(int i = 0; i < N; i++)
            job[i] = -1;
    }
    int cost = 0;
    int time = 0;
    bool isExist = true;
    bool isEnd = false;
    int job[N];
};

result minimum(result a, result b) {
    if(!a.isExist) return b;
    if(!b.isExist) return a;
    if(!a.isEnd) return b;
    if(!b.isEnd) return a;
    if(a.time > b.time) return b;       // for minimum time
    if(a.time < b.time) return a;       // .
    if(a.cost > b.cost) return a;       // .
    // if(a.cost > b.cost) return a;    // for maximum cost
    // if(a.cost < b.cost) return b;    // .
    // if(a.time < b.time) return a;    // .
    return b;
}

// backtrack function
result findBest(int income[N][N], int time[N][N], result res, int level = -1, int cur = 0) {
    if(level != -1) { // not initialize
        if(res.job[cur] != -1) { // if reserved
            res.isExist = false;
            return res; // branch and bound
        }
        res.job[cur] = level;
        res.cost += income[level][cur];
        res.time += time[level][cur];
        if(level + 1 == N) {
            res.isEnd = true;
            return res;
        }
    }

    result min;
    for(int i = 0; i < N; i++)
        min = minimum(min, findBest(income, time, res, level + 1, i));
    return min;
}

int main() {
    int income[N][N] = {
        {9, 3, 4},
        {7, 8, 4},
        {10, 5, 2}
    };

    int time[N][N] = {
        {3, 5, 4},
        {6, 2, 3},
        {11, 5, 1}
    };

    result init;
    result res = findBest(income, time, init);
    for(int i = 0; i < N; i++)
        cout << "job " << i + 1 << " doing by person " << res.job[i] + 1 << " in time " << time[res.job[i]][i] << " and income " << income[res.job[i]][i] << endl;
    cout << "Total Time: " << res.time << " and total cost: " << res.cost << endl;

    return 0;
}