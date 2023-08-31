#include<iostream>
#include<queue>
#include<set>
#include<utility>
using namespace std;
typedef pair<string, int> psi;
set<string> visit;

string endMap = "123456780";
int zeroX, zeroY; // find empty
const int ruleSet[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

int solve(string init){
    queue<psi> q;
    q.push(make_pair(init, 0));
    visit.insert(init);
    while(!q.empty()){
        string arr = q.front().first;
        int count = q.front().second;
        q.pop();

        if(arr == endMap) return count;

        for(int i=0; i<9; ++i) if(arr[i] == '0'){
            zeroX = i%3;
            zeroY = i/3;
        }

        for(int i=0; i<4; ++i){
            if(0 <= ruleSet[i][0] + zeroX && ruleSet[i][0] + zeroX < 3
            && 0 <= ruleSet[i][1] + zeroY && ruleSet[i][1] + zeroY < 3){

                string modArr = arr;

                int zeroIdx = zeroX + zeroY*3;
                int modIdx = (zeroX + ruleSet[i][0]) + (zeroY + ruleSet[i][1])*3;

                char tmp = modArr[zeroIdx];
                modArr[zeroIdx] = modArr[modIdx];
                modArr[modIdx] = tmp;

                if(visit.find(modArr) == visit.end()){
                    visit.insert(modArr);
                    q.push(make_pair(modArr, count + 1));
                }
            }
        }

    }
    return -1;
}

int main(){
    string arr;
    int tmp;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cin>>tmp;
            arr += tmp + 48;
        }
    }
    cout<<solve(arr);
}