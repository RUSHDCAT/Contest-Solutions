#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double eps = 1e-9;
const int N = 300000 + 10;
int n;
double t[N], s[N], a[N];

vector<double> vec;
int id(double x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}

double sum[N], ssum[N];
double query(double my) {
	double res = 0;

	{
		int r = id(my + acos(-1) + eps) - 1;
		int l = id(my) - 1;
		res += (r>=0?sum[r]:0) - (l>=0?sum[l]:0) - ((r>=0?ssum[r]:0) - (l>=0?ssum[l]:0)) * my;
	}

	//printf("# %.5f\n", res);

	{
		int r = id(my);
		int l = id(my - acos(-1)) - 1;
		res += ((r>=0?ssum[r]:0) - (l>=0?ssum[l]:0)) * my - ((r>=0?sum[r]:0) - (l>=0?sum[l]:0));
	}

	//printf("my = %.5f, res = %.5f\n", my, res);
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) 
		scanf("%lf%lf%lf",&t[i],&s[i],&a[i]);
	
	double ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += t[i]; 
		vec.push_back(a[i]);
		vec.push_back(a[i] + 2 * acos(-1));
		vec.push_back(a[i] - 2 * acos(-1));
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 1; i <= n; i ++) {
		sum[id(a[i])] += s[i] * a[i];
		sum[id(a[i] + 2 * acos(-1))] += s[i] * (a[i] + 2 * acos(-1));
		sum[id(a[i] - 2 * acos(-1))] += s[i] * (a[i] - 2 * acos(-1));

		ssum[id(a[i])] += s[i];
		ssum[id(a[i] + 2 * acos(-1))] += s[i];
		ssum[id(a[i] - 2 * acos(-1))] += s[i];
	}

	for (int i = 1; i < vec.size(); i ++) {
		sum[i] += sum[i-1];
		ssum[i] += ssum[i-1];
	}

	double ans2 = 1e10;
	for (int i = 1; i <= n; i ++) {
		ans2 = min(ans2, query(a[i]));
	}
	//printf("# %.4f\n", ans2);
	ans -= ans2;
	printf("%.8f\n", ans);
}

