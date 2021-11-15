#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NZ = 300;
int n, k, r, p;
int A[NZ][NZ];
ll prefix[NZ][NZ];
ll res = 0;

struct rect{ int x, y, u, v, op;};
vector<rect> E;

void read()
{
    cin >> n >> k >> r >> p;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
        cin >> A[i][j];
}

void init()
{
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        prefix[i][j] += A[i][j];
        prefix[i][j] += prefix[i-1][j];
        prefix[i][j] += prefix[i][j-1];
        prefix[i][j] -= prefix[i-1][j-1];
    }
}

rect create(int x, int y, int op){
    rect a = {x, y, x+r, y+r, op};
    return a;
}

rect insect(rect a, rect b)
{
    int x = max(a.x, b.x);
    int y = max(a.y, b.y);
    int u = min(a.u, b.u);
    int v = min(a.v, b.v);
    if (u<x || v<y)
    {
        rect tmp = {0,0,0,0,0};
        return tmp;
    }
    rect rez = {x,y,u,v,-b.op};
    return rez;
}

void addNew(rect a)
{
    int len = E.size();
    for (int i=0; i<len; i++)
        E.push_back(insect(a,E[i]));
    E.push_back(a);
}

ll cal()
{
    int x, y;
    for (int i=0; i<p; i++)
    {
        cin >> x >> y;
        rect rec = create(x-1,y-1,1);
        addNew(rec);
    }

    int len = E.size();
    ll sum = 0;
    for (int i=0; i<len; i++)
    {
        rect rz = E[i];
        //cout << "RECT: " << rz.x << " " << rz.y << " " << rz.u << " " << rz.v << " " << rz.op << endl;
        ll tmp = 0;
        tmp += prefix[rz.u][rz.v];
        tmp -= prefix[rz.u][rz.y];
        tmp -= prefix[rz.x][rz.v];
        tmp += prefix[rz.x][rz.y];
        sum += tmp*rz.op;
    }
    return sum;
}

void solve()
{
    for (int i=0; i<k; i++)
    {
        ll sum = cal();
        //cout << "sum = " << sum  << endl;
        res = max(sum, res);
        E.clear();
    }
}

void write()
{
    cout << res;
}

int main()
{
    read();
    init();
    solve();
    write();
    return 0;
}

