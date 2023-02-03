#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

// Lazy Template from: https://github.com/Priyansh19077/CP-Templates/blob/master/Range%20Queries/Lazy_SGT.cpp

template<typename Node, typename Update>
struct LazySGT {
	vector<Node> tree;
	vector<bool> lazy;
	vector<Update> updates;
	vector<ll> arr; // type may change
	int n;
	int s;
	LazySGT(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while (s < 2 * n) {
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		lazy.resize(s); fill(all(lazy), false);
		updates.resize(s); fill(all(updates), Update());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index) { // Never change this
		if (start == end)   {
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void pushdown(int index, int start, int end) {
		if (lazy[index]) {
			int mid = (start + end) / 2;
			apply(2 * index, start, mid, updates[index]);
			apply(2 * index + 1, mid + 1, end, updates[index]);
			updates[index] = Update();
			lazy[index] = 0;
		}
	}
	void apply(int index, int start, int end, Update& u) {
		if (start != end) {
			lazy[index] = 1;
			updates[index].combine(u, start, end);
		}
		u.apply(tree[index], start, end);
	}
	void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
		if (start > right || end < left)
			return;
		if (start >= left && end <= right) {
			apply(index, start, end, u);
			return;
		}
		pushdown(index, start, end);
		int mid = (start + end) / 2;
		update(start, mid, 2 * index, left, right, u);
		update(mid + 1, end, 2 * index + 1, left, right, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right) {
			pushdown(index, start, end);
			return tree[index];
		}
		pushdown(index, start, end);
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int left, int right, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, left, right, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node {
	ll val; // may change
	Node() { // Identity element
		val = 0;    // may change
	}
	Node(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node &l, Node &r) { // Merge two child nodes
		val = l.val + r.val;  // may change
	}
};

struct Update {
	ll val; // may change
	Update() { // Identity update
		val = 0;
	}
	Update(ll val1) { // Actual Update
		val = val1;
	}
	void apply(Node &a, int start, int end) { // apply update to given node
		a.val += val * (end - start + 1); // may change
	}
	void combine(Update& new_update, int start, int end) {
		val += new_update.val;
	}
};

int getSum(int n)
{
	int sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<ll> b(n, 0);
	LazySGT<Node, Update> segTree(n, b);

	vector<int> steps[n];
	for (int i = 0; i < n; i++) {
		steps[i].push_back(a[i]);
		int x = a[i];

		while (x / 10 > 0) {
			int sum = getSum(x);
			steps[i].push_back(sum);
			x = sum;
		}
	}

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;

		if (t == 1) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			segTree.make_update(l, r, 1);
		}
		else {
			int idx;
			cin >> idx;
			--idx;
			Node node = segTree.make_query(idx, idx);

			if (node.val >= (int)steps[idx].size()) {
				cout << steps[idx].back() << '\n';
			}
			else {
				cout << steps[idx][node.val] << '\n';
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}