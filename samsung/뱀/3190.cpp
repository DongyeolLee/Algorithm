#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct dir_info {
    int second;
    char direction;
};

struct snake {
    int time;
    int cur_direction;
    vector<pair<int, int>> body;
};

int N, K, L;
int map[100][100];
int snake_history[100][100];
dir_info dirInfo[100];

int change_dir(int current, char change_to) {
    if(current == 0) {
        if(change_to == 'D') {
            current++;
            return current;
        } else {
            current = 3;
            return current;
        }
    } else if(current == 1) {
        if(change_to == 'D') {
            current++;
            return current;
        } else {
            current--;
            return current;
        }
    } else if(current == 2) {
        if(change_to == 'D') {
            current++;
            return current;
        } else {
            current--;
            return current;
        }
    } else if(current == 3) {
        if(change_to == 'D') {
            current = 0;
            return current;
        } else {
            current--;
            return current;
        }
    }
}

int main() {

    cin >> N;
    cin >> K;
    for(int i = 0; i < K; i ++) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }
    cin >> L;
    for(int i = 0; i < L; i ++){
        int second;
        char dir;
        dir_info temp;
        cin >> second >> dir;
        temp.second = second ;
        temp.direction = dir;
        dirInfo[i] = temp;
    }

    snake s;
    s.time = 0;
    s.cur_direction = 1;
    s.body.push_back(make_pair(0, 0));
    int idx = 0;
    while(true) {
        int r = s.body[0].first;
        int c = s.body[0].second;
        int time = s.time;

        if(time == dirInfo[idx].second) {
            s.cur_direction = change_dir(s.cur_direction, dirInfo[idx].direction);
            idx ++;
        }

        if(s.cur_direction == 1) {
            int nextR = r;
            int nextC = c + 1;
            if(snake_history[nextR][nextC] == 1 || nextR >= N || nextC >= N || nextC < 0 || nextR < 0) {
                break;
            }
            s.body.insert(s.body.begin(), make_pair(nextR, nextC));
            snake_history[nextR][nextC] = 1;
            if(!map[nextR][nextC]) {
                int xR = s.body.back().first;
                int xC = s.body.back().second;
                snake_history[xR][xC] = 0;
                s.body.pop_back();
            } else {
                map[nextR][nextC] = 0;
            }
        } else if(s.cur_direction == 0) {
            int nextR = r - 1;
            int nextC = c;
            if(snake_history[nextR][nextC] == 1 || nextR >= N || nextC >= N || nextC < 0 || nextR < 0) {
                break;
            }
            s.body.insert(s.body.begin(), make_pair(nextR, nextC));
            snake_history[nextR][nextC] = 1;
            if(!map[nextR][nextC]) {
                int xR = s.body.back().first;
                int xC = s.body.back().second;
                snake_history[xR][xC] = 0;
                s.body.pop_back();
            } else {
                map[nextR][nextC] = 0;
            }
        } else if(s.cur_direction == 2) {
            int nextR = r + 1;
            int nextC = c;
            if(snake_history[nextR][nextC] == 1 || nextR >= N || nextC >= N || nextC < 0 || nextR < 0) {
                break;
            }
            s.body.insert(s.body.begin(), make_pair(nextR, nextC));
            snake_history[nextR][nextC] = 1;
            if(!map[nextR][nextC]) {
                int xR = s.body.back().first;
                int xC = s.body.back().second;
                snake_history[xR][xC] = 0;
                s.body.pop_back();
            } else {
                map[nextR][nextC] = 0;
            }
        } else if(s.cur_direction == 3) {
            int nextR = r;
            int nextC = c - 1;
            if(snake_history[nextR][nextC] == 1 || nextR >= N || nextC >= N || nextC < 0 || nextR < 0) {
                break;
            }
            s.body.insert(s.body.begin(), make_pair(nextR, nextC));
            snake_history[nextR][nextC] = 1;
            if(!map[nextR][nextC]) {
                int xR = s.body.back().first;
                int xC = s.body.back().second;
                snake_history[xR][xC] = 0;
                s.body.pop_back();
            }else {
                map[nextR][nextC] = 0;
            }
        }
        s.time ++;
    }
    cout << s.time + 1;
    return 0;
}
