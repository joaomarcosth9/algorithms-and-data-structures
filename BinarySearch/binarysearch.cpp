#include <iostream>
#include <vector>

using namespace std;

int binary_search(int v, vector<int>& V){
    int n = V.size();
    int l = 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(V[mid] == v) return mid;
        if(V[mid] > v){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

int main(){
    int n,v; cin >> n;
    vector<int> V(n);
    for(int i = 0; i < n; i++) cin >> V[i];
    cin >> v;
    cout << binary_search(v, V) << endl;
}
