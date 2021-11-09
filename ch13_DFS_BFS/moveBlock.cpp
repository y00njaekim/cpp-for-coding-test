#include <string>
#include <vector>
#include <queue>
#define pii pair<int, int>

using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int t = 0;
int N;

void bfs(vector<vector<int> > board) {
    vector<pii> v;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(0, 1));
    
    queue<vector<pii> > q;
    q.push(v);
    while(!q.empty()) {
        t++;
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            vector<pii> cur = q.front();
            q.pop();
            for(int k=0; k<4; k++) {
                int nr1 = cur[0].first + dr[k];
                int nc1 = cur[0].second + dc[k];
                int nr2 = cur[1].first + dr[k];
                int nc2 = cur[1].second + dc[k];
                if(nr1 < 0 || nr1 >= N) continue;
                if(nc1 < 0 || nc1 >= N) continue;
                if(nr2 < 0 || nr2 >= N) continue;
                if(nc2 < 0 || nc2 >= N) continue;
                if(board[nr1][nc1] == 1) continue;
                if(board[nr2][nc2] == 1) continue;
                vector<pii> next;
                next.push_back(make_pair(nr1, nc1));
                next.push_back(make_pair(nr2, nc2));
                q.push(next);
                if(next[0].first == N-1 && next[0].second == N-1) return;
                if(next[1].first == N-1 && next[1].second == N-1) return;
            }
            for(int j=0; j<2; j++) {
                pii robotMove = (j==0) ? cur[0] : cur[1];
                pii robotStop = (j==0) ? cur[1] : cur[0];
                for(int k=0; k<4; k++) {
                    int wr = robotMove.first + dr[k];
                    int wc = robotMove.second + dc[k];
                    if(wr < 0 || wr >= N) continue;
                    if(wc < 0 || wc >= N) continue;
                    if(wr != robotStop.first) continue;
                    if(wc != robotStop.second) continue;
                    if(k <= 1) { // 상 하
                        for(int l=2; l<4; l++) {
                            int checkR = robotMove.first + dr[l];
                            int checkC = robotMove.second + dc[l];
                            if(checkR < 0 || checkR >= N) continue;
                            if(checkC < 0 || checkC >= N) continue;
                            if(board[checkR][checkC] == 1) continue;
                            int nr = robotMove.first + dr[k] + dr[l];
                            int nc = robotMove.second + dc[k] + dc[l];
                            vector<pii> next;
                            next.push_back(make_pair(nr, nc));
                            next.push_back(robotStop);
                            q.push(next);
                            if(next[0].first == N-1 && next[0].second == N-1) return;
                            if(next[1].first == N-1 && next[1].second == N-1) return;
                        }
                    }
                    if(k > 1) { // 좌 우
                        for(int l=0; l<2; l++) {
                            int checkR = robotMove.first + dr[l];
                            int checkC = robotMove.second + dc[l];
                            if(checkR < 0 || checkR >= N) continue;
                            if(checkC < 0 || checkC >= N) continue;
                            if(board[checkR][checkC] == 1) continue;
                            int nr = robotMove.first + dr[k] + dr[l];
                            int nc = robotMove.second + dc[k] + dc[l];
                            vector<pii> next;
                            next.push_back(make_pair(nr, nc));
                            next.push_back(robotStop);
                            q.push(next);
                            if(next[0].first == N-1 && next[0].second == N-1) return;
                            if(next[1].first == N-1 && next[1].second == N-1) return;
                        }
                    }
                    
                }
            }
        }
    }
}

int solution(vector<vector<int> > board) {
    N = board.size();
    bfs(board);
    return t;
}
