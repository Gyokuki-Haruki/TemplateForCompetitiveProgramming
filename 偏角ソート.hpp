#include <bits/stdc++.h>
using namespace std;
//方法1
typedef long double LD;

int main() {

    //ランダムに生成する点の数
    int N;
    cin >> N;

    mt19937 mt;
    uniform_int_distribution<int> dist(-100, 100);

    vector<LD> x(N), y(N);
    for (int i = 0; i < N; i++) {
        x[i] = dist(mt);
        y[i] = dist(mt);
    }

    vector<pair<LD, LD>> xy(N);
    for (int i = 0; i < N; i++) xy[i] = make_pair(x[i], y[i]);

    sort(xy.begin(), xy.end(), [](const auto &p1, const auto &p2) {
        return atan2l(p1.second, p1.first) < atan2l(p2.second, p2.first);
    });

    for (int i = 0; i < N; i++) {
        cout << "(" << xy[i].first << ", " << xy[i].second << ") : " << atan2l(xy[i].second, xy[i].first) << endl;
    }

}

// 方法2
struct point {
    int x, y;
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}

bool cmp(const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}

void argument_sort(vector<point> &points) {
    sort(points.begin(), points.end(), cmp);
}
