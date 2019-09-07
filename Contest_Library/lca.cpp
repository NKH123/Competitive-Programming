const int N = 210000;
 
const int l = 17;
 
int timer;
int up[N][l + 1];
int bedge[N][l + 1];
int tin[N];
int tout[N];
int dep[N];
 
void dfs(int v, int p = 1,int pcost=0)
{
    tin[v] = timer;
    ++timer;
    up[v][0] = p;
    bedge[v][0] = pcost;
    for (int i = 1; i <= l; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
        bedge[v][i] = max(bedge[v][i - 1], bedge[up[v][i-1]][i - 1]);
    }
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i].first;
        int cost = g[v][i].second;
        if (to == p)
            continue;
        dep[to] = dep[v] + 1;
        dfs(to, v, cost);
    }
    tout[v] = timer;
    ++timer;
}
 
bool upper(int a, int b)
{
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}
 
int lca(int a, int b)
{
    if (upper(a, b))
        return a;
    if (upper(b, a))
        return b;
    for (int i = l; i >= 0; --i)
    {
        if (!upper(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}