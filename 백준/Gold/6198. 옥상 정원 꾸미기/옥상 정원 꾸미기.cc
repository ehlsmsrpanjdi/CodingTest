//{
//	//ios::sync_with_stdio(0);
//	//cin.tie(0);
//#include "iostream"
//#include "vector"
//#include "list"
//#include "map"
//#include "queue"
//	using namespace std;
//
//	bool isPuyo; // 뿌요가 터졌는지 여부
//	bool vis[12][6]; // 필드 방문 여부
//	bool movearr[12][6]; // 필드 방문 여부
//	int dist[12][6]; // 필드 방문 여부
//	string board[12]; // 필드 상태
//	int di[4] = { 0, 1, 0, -1 };
//	int dj[4] = { 1, 0, -1, 0 };
//	int ans;
//
//	int R, G, B, P, Y;
//
//	int Reset() {
//		R = 0, G = 0, B = 0, P = 0, Y = 0;
//		return 0;
//	}
//
//	int Reset(char _type) {
//		switch (_type) {
//		case 'R':
//			G = 0, B = 0, P = 0, Y = 0;
//			return ++R;
//			break;
//		case 'G':
//			R = 0, B = 0, P = 0, Y = 0;
//			return ++G;
//			break;
//		case 'B':
//			R = 0, G = 0, P = 0, Y = 0;
//			return ++B;
//			break;
//		case 'P':
//			R = 0, G = 0, B = 0, Y = 0;
//			return ++P;
//			break;
//		case 'Y':
//			R = 0, G = 0, B = 0, P = 0;
//			return ++Y;
//			break;
//		}
//	}
//
//	void resetVis() {
//		for (int i = 0; i < 12; ++i)
//			for (int j = 0; j < 6; ++j)
//				vis[i][j] = false;
//	}
//
//	void resetmove() {
//		for (int i = 0; i < 12; ++i)
//			for (int j = 0; j < 6; ++j)
//				movearr[i][j] = false;
//	}
//
//	class Puyo {
//	public:
//		Puyo(int _i, int _j, int _type)
//			:i(_i)
//			, j(_j)
//			, Type(_type)
//		{
//
//		}
//		int i = -1;
//		int j = -1;
//		int Type = -1;
//
//		bool ismove = false;
//	};
//
//	bool bottomcheck(int _tempi, int _tempj, int Type) {
//		int tempi = _tempi + 1;
//		if (tempi >= 0 && _tempj >= 0 && _tempj < 12 && tempi < 12) {
//			if (board[tempi][_tempj] == 46 || movearr[tempi][_tempj] == true) {
//				board[tempi][_tempj] = Type;
//				board[_tempi][_tempj] = 46;
//				movearr[tempi][_tempj] = true;
//				movearr[_tempi][_tempj] = true;
//				return true;
//			}
//			else if (board[tempi][_tempj] != 46) {
//				if (true == bottomcheck(tempi, _tempj, Type) == true) {
//					board[tempi][_tempj] = Type;
//					board[_tempi][_tempj] = 46;
//					movearr[tempi][_tempj] = true;
//					movearr[_tempi][_tempj] = true;
//					return true;
//				}
//			}
//		}
//
//		return false;
//	}
//
//	int main() {
//		ios::sync_with_stdio(0);
//		cin.tie(0);
//
//		std::list<Puyo> Exist;
//		std::list<Puyo> Four;
//		std::list<Puyo> Destroy;
//
//		std::queue<Puyo> qu;
//
//		for (int i = 0; i < 12; ++i)
//		{
//			cin >> board[i];
//			for (int j = 0; j < 6; ++j) {
//				if (board[i][j] != 46) {
//					Exist.push_back(Puyo(i, j, board[i][j]));
//				}
//			}
//		}
//
//
//		for (Puyo& puyo : Exist) {
//			int tempi;
//			int tempj;
//
//			if (vis[puyo.i][puyo.j] == true) {
//				continue;
//			}
//
//			qu.push(puyo);
//
//			while (!qu.empty()) {
//				Puyo Ptemp = qu.front();
//				qu.pop();
//				for (int i = 0; i < 4; ++i) {
//					tempi = Ptemp.i + di[i];
//					tempj = Ptemp.j + dj[i];
//
//					if (tempi >= 0 && tempj >= 0 && tempj < 12 && tempi < 12) {
//						if (board[tempi][tempj] == Ptemp.Type && vis[tempi][tempj] == false) {
//							vis[tempi][tempj] = true;
//							dist[tempi][tempj] = dist[Ptemp.i][Ptemp.j] + 1;
//							dist[tempi][tempj] = Reset(board[tempi][tempj]);
//							qu.push(Puyo(tempi, tempj, board[tempi][tempj]));
//						}
//					}
//				}
//			}
//		}
//
//		resetVis();
//
//		for (Puyo& puyo : Exist) {
//			int tempi;
//			int tempj;
//
//			if (dist[puyo.i][puyo.j] < 4) {
//				continue;
//			}
//
//			qu.push(puyo);
//
//			while (!qu.empty()) {
//				Puyo Ptemp = qu.front();
//				qu.pop();
//				for (int i = 0; i < 4; ++i) {
//					tempi = Ptemp.i + di[i];
//					tempj = Ptemp.j + dj[i];
//
//					if (tempi >= 0 && tempj >= 0 && tempj < 12 && tempi < 12) {
//						if (board[tempi][tempj] == Ptemp.Type && vis[tempi][tempj] == false) {
//							vis[tempi][tempj] = true;
//							dist[tempi][tempj] = 4;
//							qu.push(Puyo(tempi, tempj, board[tempi][tempj]));
//						}
//					}
//				}
//			}
//		}
//
//
//		for (std::list<Puyo>::iterator iter = Exist.begin(); iter != Exist.end();) {
//			if (dist[iter->i][iter->j] >= 4) {
//				board[iter->i][iter->j] = 46;
//				iter = Exist.erase(iter);
//				continue;
//			}
//			++iter;
//		}
//
//		for (Puyo& puyo : Exist) {
//			int tempi = puyo.i + 1;
//			int tempj = puyo.j;
//
//			if (movearr[puyo.i][puyo.j] == true) {
//				continue;
//			}
//
//			if (tempi >= 0 && tempj >= 0 && tempj < 12 && tempi < 12) {
//				if (board[tempi][tempj] == 46 || movearr[tempi][tempj] == true) {
//					board[tempi][tempj] = puyo.Type;
//					board[puyo.i][puyo.j] = 46;
//					movearr[tempi][tempj] = true;
//					movearr[puyo.i][puyo.j] = true;
//				}
//				else if (board[tempi][tempj] != 46) {
//					if (true == bottomcheck(tempi, tempj, puyo.Type)) {
//						board[tempi][tempj] = puyo.Type;
//						board[puyo.i][puyo.j] = 46;
//						movearr[tempi][tempj] = true;
//						movearr[puyo.i][puyo.j] = true;
//					}
//				}
//			}
//		}
//
//		resetmove();
//
//		return 0;
//	}
//}
#include "iostream"
#include "list"
#include "algorithm"
#include "stack"
#include "queue"
using namespace std;
#define ll long long

stack<int> s;
int n;
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll h;
    while (n--) {
        cin >> h;
        while (!s.empty() && s.top() <= h)
            s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
    return 0;
}