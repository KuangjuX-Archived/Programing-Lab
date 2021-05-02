#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int N, i, coach, k;
bool cont;

stack< int > station;

int main() {

    // freopen("input.txt", "r", stdin);

    while (true) {

        scanf("%d\n", &N);

        if (!N) {
            break;
        }

        while (true) {

            while (!station.empty()) {
                station.pop();
            }

            for (k = i = 0; i < N; i++) {

                scanf("%d ", &coach);

                if (!coach) {
                    break;
                }

                while (k < N && k != coach) {
                    if (station.size() > 0 && station.top() == coach) {
                        break;
                    }

                    station.push(++k);
                }

                if (station.top() == coach) {
                    station.pop();
                }

            }

            if (!coach) {
                break;
            }

            if (!station.size()) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

        printf("\n");
    }

    return 0;
};