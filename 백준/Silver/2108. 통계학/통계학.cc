#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int i_minus[4001]; // -1 ~ -4000
int i_natural[4001]; // 0 ~ 4000

int i_min;
int i_max;

int most_idx;
int most_val;
bool is_secondary;

int arr[500001];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    double avg = 0;
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
        i_min = i == 0 || i_min > arr[i] ? arr[i] : i_min;
        i_max = i == 0 || i_max < arr[i] ? arr[i] : i_max;
        avg += (double) arr[i];
        if(arr[i] < 0) {
            i_minus[-arr[i]]++;
            
        }
        else {
            i_natural[arr[i]]++;
        }
    }
    sort(arr, arr + n);
    for(int i=i_min; i<=i_max; ++i) {
        if(i < 0) {
            if(i_minus[-i] > most_val) {
                most_val = i_minus[-i];
                most_idx = i;
                is_secondary = false;
            }
            else if(i_minus[-i] == most_val && !is_secondary) {
                most_idx = i;
                is_secondary = true;
            }
        }
        else {
            if(i_natural[i] > most_val) {
                most_val = i_natural[i];
                most_idx = i;
                is_secondary = false;
            }
            else if(i_natural[i] == most_val && !is_secondary) {
                most_idx = i;
                is_secondary = true;
            }
        }
        
    }
    avg /= n;

    cout<<round(avg) + 0.0<<'\n';
    cout<<arr[n/2]<<'\n';
    cout<<most_idx<<'\n';
    cout<<i_max-i_min;

}