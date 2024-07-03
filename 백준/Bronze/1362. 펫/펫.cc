#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int seq = 0;
    while (1) {
        bool dead = false;
        int w, o;
        cin >> o >> w;
        if (!w && !o)
            break;
        while (1) {
            string cmd;
            int v;
            cin >> cmd >> v;
            if (cmd[0] == '#') {
                seq++;
                if (dead)
                    cout << seq << " RIP\n";
                else if (o >= 2 * w || 2 * o <= w)
                    cout << seq << ' ' << ":-(\n";
                else
                    cout << seq << ' ' << ":-)\n";
                break;
            } else if (cmd[0] == 'F') {
                w += v;
            } else if (cmd[0] == 'E') {
                w -= v;
                if (w <= 0) {
                    dead = true;
                }
            }
        }
    }
}