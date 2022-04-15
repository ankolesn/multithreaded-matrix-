//многопоточное сложение матриц
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

auto addEl(const vector<int> &v1, const vector<int> &v2, vector<int> &res) {
    res = v1;
    for(int i = 0; i < res.size(); ++i) {
        res[i] += v2[i];
    }
}

auto add(const vector<vector<int>> &v1, const vector<vector<int>> &v2){
    vector<thread> thr;
    vector<vector<int>> res(v1.size());
    for (int i = 0; i < v1.size(); ++i) {
        thr.push_back(thread(addEl, ref(v1[i]), ref(v2[i]), ref(res[i])));
        //res[i] = addEl(v1[i], v2[i]);
    }
    for(auto && th: thr){
        th.join();
    }
    return res;
}

int main() {
    int r = 5;
    int c = 5;
    vector<vector<int>> v(r);
    for(auto &vi:v){
        vi.resize(c);
    }
    for(auto &i: v){
        for(auto &j: i){
            j = rand()%10;
        }
    }
    for(auto &i: v){
        for(auto &j: i){
            cout << j << ' ';
        }
        cout << endl;
    }
    auto res = add(v, v);
    for(auto &i: res){
        for(auto &j: i){
            cout << j << ' ';
        }
        cout << endl;
    }
}
