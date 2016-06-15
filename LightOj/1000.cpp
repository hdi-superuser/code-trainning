#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    int cnt = 0;
    while (T--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << "Case " << ++cnt << ": " << x + y << std::endl;
    }
}
