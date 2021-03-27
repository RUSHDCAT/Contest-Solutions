#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n;
string s, t;

string ans = "";
string sub(string str) {
	int las = -1;
	for (int i = n - 1; i >= 0; i --) if (str[i] == '1') {
		las = i; break;
	}

	if (las == -1) return str;
	str[las] = '0';
	for (int i = las + 1; i < n; i ++) str[i] = '1';
	return str; 
}
string plu(string str) {
	int las = -1;
	for (int i = n - 1; i >= 0; i --) if (str[i] == '0') {
		las = i; break;
	}
	if (las == -1) return str;
	str[las] = '1';
	for (int i = las + 1; i < n; i ++) str[i] = '0';
	return str; 	
}
string solve(string l, string r) {
	string ans = l;
	if (l == r) {
		for (int i = 0; i < ans.length(); i ++) 
			ans[i] = (char)('0' + ((l[i]-'0')^(r[i]-'0')));
		return ans;
	}
	bool flag = 0;
	for (int i = 0; i < ans.length(); i ++) {
		if (l[i] == r[i] && flag == 0) {
			ans[i] = '0';
		} else {
			flag = 1; ans[i] = '1';
		}
	}
	return ans;
}
string solve(string x, string l, string r) {
	int flag = 0, done = 0;
	int len = l.length();
	string ans = l;
	for (int i = 0; i < len; i ++) {
		if (flag == 0) {
			if (l[i] == r[i]) ans[i] = (char)('0' + (x[i]-'0')^(l[i]-'0'));
			else {
				if (l[i] == x[i]) {
					flag = 2;
				} else if (r[i] == x[i]) {
					flag = 1;
				}
				ans[i] = '1';
			}
			continue;
		}
		if (flag == 1) {
			if (x[i] == '0') {
				ans[i] = '1';
				if (l[i] == '0') done = 1;
			} else {
				if (done) ans[i] = '0'; else ans[i] = '1';
			}
		}
		if (flag == 2) {
			if (x[i] == '1') {
				ans[i] = '1';
				if (r[i] == '1') done = 1;
			} else {
				if (done) ans[i] = '0'; else ans[i] = '1';	
			}
		}
	}
	return ans;
}
string solve(string l1, string l2, string r1, string r2) {
	//cout << "solve " << l1 <<" "<<l2<<" "<<r1<<" "<<r2<<endl;
	string ans1 = solve(l1, r1, r2);
	string ans2 = solve(l2, r1, r2);
	string ans3 = solve(r1, l1, l2);
	string ans4 = solve(r2, l1, l2);
	string ans5 = solve(max(l1,r1),min(r2,l2));
	if(max(l1,r1)>min(r2,l2)) for(int i=0;ans5[i];i++) ans5[i]='0';
	//cout << "ans " << ans1 << " "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<endl;
	return max({ans1,ans2,ans3,ans4,ans5});
}
int toInt(string s) {
	int x = 0;
	for (int i = 0; s[i]; i ++) 
		x = x * 2 + (s[i] - '0');
	return x;
}

pair<string, string> shrink(string l, string r, string suffix) {
	string suffix_l = l.substr(n-2,2);
	string suffix_r = r.substr(n-2,2);
	string ans_l, ans_r;
	if (suffix_l > suffix) ans_l = plu(l.substr(0,n-2)); else ans_l = l.substr(0,n-2);
	if (suffix_r < suffix) ans_r = sub(r.substr(0,n-2)); else ans_r = r.substr(0,n-2);
	return make_pair(ans_l, ans_r); 
}
void dog(pair<string,string> &s) {
	string zero=s.first;
	for(int i=0;zero[i];i++) zero[i]='0';
	s=make_pair(zero,zero);
}
string merge(string x, string y) {
	if(y[0]=='1') x[0]=(char)((int)'0'+'1'-x[0]);
	if(y[1]=='1') x[1]=(char)((int)'0'+'1'-x[1]);
	return x;
} 
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> s >> t;

    if (n <= 2) {
    	int l = toInt(s), r = toInt(t);
    	int ans = 0;
    	for (int i = l; i <= r; i ++) {
    		for (int j = i; j <= r; j ++) {
    			int x = 0;
    			for (int k = l; k <= r; k ++) x ^= k;
    			ans = max(x, ans);
    		}
    	}
    	for (int i = n-1;i>=0;i--) cout<<(ans>>i&1);
    	cout << endl;
   		return 0;
    }
    
    string R[2] = {s, t};
    string L[2] = {sub(s), sub(t)};

    pair<string, string> pr[4], pl[4];

    pr[0] = shrink(R[0], R[1], "00"); 
    pr[1] = shrink(R[0], R[1], "01"); if (pr[1].first <= pr[1].second) dog(pr[1]);
    pr[2] = shrink(R[0], R[1], "10");
    pr[3] = shrink(R[0], R[1], "11"); if (pr[3].first <= pr[3].second) dog(pr[3]);

    pl[0] = shrink(L[0], L[1], "00");
    pl[1] = shrink(L[0], L[1], "01"); if (pl[1].first <= pl[1].second) dog(pl[1]);
    pl[2] = shrink(L[0], L[1], "10");
    pl[3] = shrink(L[0], L[1], "11"); if (pl[3].first <= pl[3].second) dog(pl[3]);

    string sf[4] = {"00","01","11","00"};
    for (int i = 0; i < 4; i ++) if (pl[i].first <= pl[i].second) for (int j = 0; j < 4; j ++) if (pr[j].first <= pr[j].second) {
    	//cout << "i="<<i<<"j="<<j<<endl;
    	auto tmp = solve(pl[i].first, pl[i].second, pr[j].first, pr[j].second) + merge(sf[i], sf[j]);
    	ans = max(ans, tmp);
    	//cout<<"# "<<tmp<<endl;
    }
    cout << ans << endl;
}