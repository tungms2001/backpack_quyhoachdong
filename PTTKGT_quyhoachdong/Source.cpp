#include <iostream>
#include <Windows.h>
using namespace std;

int N, M;	//khoi tao bien voi M la khoi luong tong cua gio hang va N la so luong mon do bo vao

struct Package {
	int W = 0, V = 0;	//bien khoi luong va gia tri cua goi hang thu i, gan gia tri mac dinh = 0
};

Package a[200];	//mang so luong mon hang
int dp[110][110];		//tao mang 2 chieu tuong ung voi W va V
int res = 0;

void Solve() {	//xay dung ham quy hoach dong de chay vong lap va ap dung cong thuc truy hoi de chon ra mon hang phu hop
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j < a[i].W)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].W] + a[i].V);
			res = max(res, dp[i][j]);
		}
	}
}

int main() {
	cin >> N >> M;	//nhap so luong mon hang va khoi luong tong cua gio hang
	for (int i = 1; i <= N; i++)
		cin >> a[i].W >> a[i].V;	//nhap khoi luong va gia tri cua tung mon hang

	Solve();
	
	cout << endl;
	cout << "Gia tri toi da thu duoc la: ";
	cout << res;	//tra ve ket qua la tong gia tri co duoc
	return 0;
}