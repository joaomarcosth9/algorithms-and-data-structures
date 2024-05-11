#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> &arr) {
    cout << '[';
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ',';
    }
    cout << arr[arr.size() - 1];
    cout << ']';
    cout << endl;
}

void insertion_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> V;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        V.push_back(n);
    }
    cout << "Vector before sorting: ";
    print_vector(V);
    cout << endl;
    insertion_sort(V);
    cout << "Vector after sorting: ";
    print_vector(V);
    cout << endl;

    return 0;
}
