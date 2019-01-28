/**
 *    author:  tourist
 *    created: 22.04.2018 19:03:44       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector< vector<int> > g;
  int n;

  function<bool(int)> ignore;

  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
    }
    return rev;
  }
};

template <typename T>
vector<int> find_scc(const digraph<T> &g, int &cnt) {
  digraph<T> g_rev = g.reverse();
  vector<int> order;
  vector<bool> was(g.n, false);
  function<void(int)> dfs1 = [&](int v) {
    was[v] = true;
    for (int id : g.g[v]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int to = e.to;
      if (!was[to]) {
        dfs1(to);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < g.n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  vector<int> c(g.n, -1);
  function<void(int)> dfs2 = [&](int v) {
    for (int id : g_rev.g[v]) {
      if (g_rev.ignore != nullptr && g_rev.ignore(id)) {
        continue;
      }
      auto &e = g_rev.edges[id];
      int to = e.to;
      if (c[to] == -1) {
        c[to] = c[v];
        dfs2(to);
      }
    }
  };
  cnt = 0;
  for (int id = g.n - 1; id >= 0; id--) {
    int i = order[id];
    if (c[i] != -1) {
      continue;
    }
    c[i] = cnt++;
    dfs2(i);
  }
  return c;
  // c[i] <= c[j] for every edge i -> j
}

class twosat {
  public:
  digraph<int> g;
  int n;

  twosat(int _n) : g(digraph<int>(2 * _n)), n(_n) {
  }

  inline void add(int x, int value_x) {
    // (v[x] == value_x)
    assert(0 <= x && x < n);
    assert(0 <= value_x && value_x <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * x + value_x);
  }
  
  inline void add(int x, int value_x, int y, int value_y) {
    // (v[x] == value_x || v[y] == value_y)
    assert(0 <= x && x < n && 0 <= y && y < n);
    assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * y + value_y);
    g.add(2 * y + (value_y ^ 1), 2 * x + value_x);
  }

  inline vector<int> solve() {
    int cnt;
    vector<int> c = find_scc(g, cnt);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (c[2 * i] == c[2 * i + 1]) {
        return vector<int>();
      }
      res[i] = (c[2 * i] < c[2 * i + 1]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> v[i];
    }
    double low = 0.0, high = 1e11;
    for (int it = 0; it < 80; it++) {
      double mid = 0.5 * (low + high);
      twosat ts(n);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int di = 0; di <= 1; di++) {
            for (int dj = 0; dj <= 1; dj++) {
              int dx = x[i] - x[j];
              int dv = (dj == 0 ? v[j] : -v[j]) - (di == 0 ? v[i] : -v[i]);
              if ((long long) dx * dv > 0) {
                double t = 1.0 * dx / dv;
                if (t < mid) {
                  ts.add(i, di, j, dj);
                }
              }
            }
          }
        }
      }
      if (!ts.solve().empty()) {
        low = mid;
      } else {
        high = mid;
      }
    }
    if (low > 1e10) {
      cout << "-1" << '\n';
    } else {
      cout << fixed << setprecision(10);
      cout << 0.5 * (low + high) << '\n';
    }
  }
  return 0;
}
