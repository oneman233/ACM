#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
};

struct e{
    int v,to;
    e(int vv,int toto){v=vv,to=toto;}
}

class Solver {

    int solve(int n, const vector<Edge> &edges) {
    /**********  Begin  **********/
    vector<e> p[100005];
    for(int i=0;i<edges.size();++i)
        p[edges[i].u].push_back(e(edges[i].v,edges[i].w));

    /**********  End  **********/
  }
};

#endif
