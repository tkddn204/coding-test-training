#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int in_order[100000];
int post_order[100000];
int position[100001];

void solve(int, int, int, int);

int main() {
    FAST_IO

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> in_order[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post_order[i];
    }

    for (int i = 0; i < n; i++) {
        position[in_order[i]] = i;
    }

    solve(0, n - 1, 0, n - 1);

    return 0;
}

void solve(
        int in_order_start,
        int in_order_end,
        int post_order_start,
        int post_order_end) {
    if (in_order_start > in_order_end ||
        post_order_start > post_order_end) {
        return;
    }

    int root = post_order[post_order_end];
    cout << root << " ";

    int root_index = position[root];
    int left_number = root_index - in_order_start;

    // left
    solve(in_order_start,
          root_index - 1,
          post_order_start,
          post_order_start + left_number - 1);

    // right
    solve(root_index + 1,
          in_order_end,
          post_order_start + left_number,
          post_order_end - 1);
}