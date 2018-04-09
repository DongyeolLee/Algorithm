#include <iostream>
#include <queue>

using namespace std;

struct node {
    int redR;
    int redC;
    int blueR;
    int blueC;
    int redGoal = 0;
    int blueGoal = 0;
    int cnt = 0;
};

int N, M;
int map[11][11];
queue<node> q;

int main() {
    cin >> N >> M;

    char c;
    node n;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j ++) {
            cin >> c;

            if(c == '#') {
                map[i][j] = - 1;
            } else if (c == '.') {
                map[i][j] = 0;
            } else if(c == 'O') {
                map[i][j] = 1;
            } else if(c == 'R') {
                n.redR = i;
                n.redC = j;
            } else {
                n.blueR = i;
                n.blueC = j;
            }
        }
    }

    q.push(n);

    while(!q.empty()){
        if(q.front().cnt >= 10)
            break;

        for (int dir = 0; dir < 4; dir++) {
            if (dir == 0) {
                node temp = q.front();
                int redNR = temp.redR;
                int blueNR = temp.blueR;
                while (map[redNR - 1][temp.redC] != -1) {
                    if (map[redNR - 1][temp.redC] == 1) {
                        temp.redGoal = 1;
                        break;
                    }
                    redNR--;
                }
                while (map[blueNR - 1][temp.blueC] != -1) {
                    if (map[blueNR - 1][temp.blueC] == 1) {
                        temp.blueGoal = 1;
                        break;
                    }
                    blueNR--;
                }
                if (temp.blueC == temp.redC && redNR == blueNR) {
                    if (temp.redR < temp.blueR) {
                        blueNR++;
                    } else {
                        redNR++;
                    }
                }
                if (temp.blueGoal == 0 && temp.redGoal == 1) {
                    cout << temp.cnt + 1;
                    return 0;
                }
                if (temp.blueGoal == 0 && temp.redGoal == 0) {
                    temp.cnt++;
                    temp.blueR = blueNR;
                    temp.redR = redNR;
                    q.push(temp);
                }
            } else if (dir == 1) {
                node temp = q.front();
                int redNR = temp.redR;
                int blueNR = temp.blueR;
                while (map[redNR + 1][temp.redC] != -1) {
                    if (map[redNR + 1][temp.redC] == 1) {
                        temp.redGoal = 1;
                        break;
                    }
                    redNR++;
                }
                while (map[blueNR + 1][temp.blueC] != -1) {
                    if (map[blueNR + 1][temp.blueC] == 1) {
                        temp.blueGoal = 1;
                        break;
                    }
                    blueNR++;
                }
                if (temp.blueC == temp.redC && redNR == blueNR) {
                    if (temp.redR < temp.blueR) {
                        redNR--;
                    } else {
                        blueNR--;
                    }
                }
                if (temp.blueGoal == 0 && temp.redGoal == 1) {
                    cout << temp.cnt + 1;
                    return 0;
                }
                if (temp.blueGoal == 0 && temp.redGoal == 0) {
                    temp.cnt++;
                    temp.blueR = blueNR;
                    temp.redR = redNR;
                    q.push(temp);
                }
            } else if (dir == 2) {
                node temp = q.front();
                int redNC = temp.redC;
                int blueNC = temp.blueC;
                while (map[temp.redR][redNC - 1] != -1) {
                    if (map[temp.redR][redNC - 1] == 1) {
                        temp.redGoal = 1;
                        break;
                    }
                    redNC--;
                }
                while (map[temp.blueR][blueNC - 1] != -1) {
                    if (map[temp.blueR][blueNC - 1] == 1) {
                        temp.blueGoal = 1;
                        break;
                    }
                    blueNC--;
                }
                if (temp.blueR == temp.redR && redNC == blueNC) {
                    if (temp.redC < temp.blueC) {
                        blueNC++;
                    } else {
                        redNC++;
                    }
                }
                if (temp.blueGoal == 0 && temp.redGoal == 1) {
                    cout << temp.cnt + 1;
                    return 0;
                }
                if (temp.blueGoal == 0 && temp.redGoal == 0) {
                    temp.cnt++;
                    temp.blueC = blueNC;
                    temp.redC = redNC;
                    q.push(temp);
                }
            } else {
                node temp = q.front();
                int redNC = temp.redC;
                int blueNC = temp.blueC;
                while (map[temp.redR][redNC + 1] != -1) {
                    if (map[temp.redR][redNC + 1] == 1) {
                        temp.redGoal = 1;
                        break;
                    }
                    redNC++;
                }
                while (map[temp.blueR][blueNC + 1] != -1) {
                    if (map[temp.blueR][blueNC + 1] == 1) {
                        temp.blueGoal = 1;
                        break;
                    }
                    blueNC++;
                }
                if (temp.blueR == temp.redR && redNC == blueNC) {
                    if (temp.redC < temp.blueC) {
                        redNC--;
                    } else {
                        blueNC--;
                    }
                }
                if (temp.blueGoal == 0 && temp.redGoal == 1) {
                    cout << temp.cnt + 1;
                    return 0;
                }
                if (temp.blueGoal == 0 && temp.redGoal == 0) {
                    temp.cnt++;
                    temp.blueC = blueNC;
                    temp.redC = redNC;
                    q.push(temp);
                }
            }
        }
        q.pop();
    }

    cout << -1;
    return 0;
}