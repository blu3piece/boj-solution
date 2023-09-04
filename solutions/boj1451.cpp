#include<iostream>
#include<string>
using namespace std;

long long partSum(int** map, int fromVert, int toVert, int fromHori, int toHori){
    long long sum = 0;
    for(int i = fromVert; i<toVert; ++i){
        for(int j = fromHori; j<toHori; ++j){
            sum += map[i][j];
        }
    }
    return sum;
}

int main(){
    int vert, hori; cin>>vert>>hori;
    int** map = new int*[vert];
    for(int i = 0; i<vert; ++i)
        map[i] = new int[hori];
    for(int i = 0; i<vert; ++i){
        string input; cin>>input;
        for(int j = 0; j<hori; ++j)
            map[i][j] = input[j] - 48;
    }
    long long ans = -1;
    long long value;
    for(int i = 1; i<vert; ++i){
        for(int j = i+1; j<vert; ++j){
            long long sum1 = partSum(map, 0, i, 0, hori);
            long long sum2 = partSum(map, i, j, 0, hori);
            long long sum3 = partSum(map, j, vert, 0, hori);
            value = sum1*sum2*sum3;
            ans = ans < value ? value : ans;
        }
    }
    for(int i = 1; i<hori; ++i){
        for(int j = i + 1; j<hori; ++j){
            long long sum1 = partSum(map, 0, vert, 0, i);
            long long sum2 = partSum(map, 0, vert, i, j);
            long long sum3 = partSum(map, 0, vert, j, hori);
            value = sum1*sum2*sum3;
            ans = ans < value ? value : ans;
        }
    }
    for(int i = 1; i<vert; ++i){
        for(int j = 1; j<hori; ++j){
            long long sum1 = partSum(map, 0, i, 0, j);
            long long sum2 = partSum(map, i, vert, 0, j);
            long long sum3 = partSum(map, 0, i, j, hori);
            long long sum4 = partSum(map, i, vert, j, hori);

            long long candidate[4];
            candidate[0] = (sum1+sum2)*sum3*sum4;
            candidate[1] = (sum1+sum3)*sum2*sum4;
            candidate[2] = (sum3+sum4)*sum1*sum2;
            candidate[3] = (sum2+sum4)*sum1*sum3;
            for(int t = 0; t<4; ++t){
                ans = ans < candidate[t] ? candidate[t] : ans;
            }
        }
    }
    cout<<ans;
    return 0;
}