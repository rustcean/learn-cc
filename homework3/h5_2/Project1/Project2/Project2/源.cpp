#include<iostream>
#include<cstring>
using namespace std;
const int N = 100000;
struct node {
	string a;
	int arr_time;
	void to_time(int a, int b) {
		arr_time = a * 60 + b;
	}
	void time_to(int& a, int& b) {
		a = arr_time / 60;
		b = arr_time % 60;
	}
};
class stack {
public:
	node stk[N];
	int top = -1;
	void push(node a) {
		stk[++top] = a;
	}
	void pop() {
		if (empty())puts("stack is empty");
		else top--;
	}
	void print() {
		for (int i = 0; i <= top; i++) {
			int a, b;
			auto t = stk[top];
			t.time_to(a, b);
			cout << t.a << " " << a << ":" << b << endl;
		}
    }
	node query(string a) {
		for (int i = 0; i <= top; i++) {
			if (i == N)i = 0;
			auto t = stk[i];
			if (t.a == a)return t;
		}

	}
	void clear() {
		top = -1;
		print();
	}
	bool empty() {
		return top == -1;
	}
	bool full() {
		return top == N - 1;
	}
	
};
class queue {
public:
	node q[N];
	int hh = 0, tt = -1;
	void clear() {
		hh = 0, tt = -1;
	}
	bool empty() {
		return hh==tt+1;
	}
	bool full() {
		return hh == tt + 2;
	}
	void push(node a) {
		q[++tt] = a;
		if (tt == N)tt = -1;
	}
	void pop() {
		hh++;
		if (hh == N)hh = 0;
	}
	void print() {
		for (int i = hh; i <= tt; i++) {
			int a, b;
			if (i == N)i = 0;
			auto t = q[i];
			t.time_to(a, b);
			cout << t.a << endl;
		}
	}
	node query(string a) {
		for (int i = hh; i <= tt; i++) {
			if (i == N)i = 0;
			auto t = q[i];
			if (t.a == a)return t;
		}
		
	}

};
string a[5] = { "car arrive","car leave","All car in park","All car in waiting room","exit" };
int main() {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << endl;
	}
	int x;
	while (cin >> x, x != 5) {
		stack stk;
		queue q;
		if (x == 1) {
			string c;
			cin >> c;
			int a, b;
			scanf("%d:%d", &a, &b);
			node d;
			d.a = c;
			d.to_time(a, b);
			if (stk.full()) { q.push(d); }
			else stk.push(d);
		}
		else if (x == 2) {
			string c;
			cin >> c;
			node d = stk.query(c);
			if (d.a.empty())d = q.query(c);
			int a, b;
			scanf("%d:%d", &a, &b);
			int x, y;
			d.time_to(x, y);
			cout << (a - x) * 60 + (b - x);
		}
		else if (x == 3) {
			stk.print();
		}
		else if (x == 4) {
			q.print();
		}
	}
}