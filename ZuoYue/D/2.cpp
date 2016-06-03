#include <cstdio>
#include <cstdlib>
#include <cstring>
class INT {
    int d[1000];
    int dn;
public:
    INT(int x = 0) {
        for (dn = 0; x != 0; x /= 10) d[dn++] = x % 10;
        if (dn == 0) {
            d[0] = 0;
            dn = 1;
        }
    }
    INT(const INT &o) {
        *this = o;
    }
    INT &operator = (const INT &o) {
        dn = o.dn;
        for (int i = 0; i < dn; i++) d[i] = o.d[i];
        return *this;
    }
    void mod10n(int n) {
        if (dn > n) dn = n;
        while (dn > 1 && d[dn - 1] == 0) dn--;
    }
    void mul(const INT &o) {
        int t[1000];
        int i, j, k = dn + o.dn;
        for (i = 0; i < k; i++) t[i] = 0;
        for (i = 0; i < o.dn; i++) {
            int x = o.d[i];
            for (j = 0; j < dn; j++) {
                t[i + j] += x * d[j];
            }
        }
        for (i = 0; i < k; i++) {
            t[i + 1] += t[i] / 10;
            t[i] %= 10;
        }
        while (k > 1 && t[k - 1] == 0) k--;
        dn = k;
        for (i = 0; i < k; i++) d[i] = t[i];
    }
    bool equal(const INT &o) const {
        if (dn != o.dn) return false;
        for (int i = 0; i < dn; i++) {
            if (d[i] != o.d[i]) return false;
        }
        return true;
    }
    void input(char *s) {
        dn = strlen(s);
        for (int i = 0; i < dn; i++) d[i] = s[dn - 1 - i] - '0';
    }
    void print() const {
        for (int i = dn - 1; i >= 0; i--) printf("%d", d[i]);
        printf("\n");
    }
}ans, x1, x2, now;
int getcircle(INT a, int k) {
    INT x1 = a;
    INT x2 = a;
    int ans = 0;
    do {
        x1.mul(a);
        x1.mod10n(k);
        ans++;
    } while (ans <= 100 && !x1.equal(x2));
    return ans > 10 ? -1 : ans;
}
main() {
    int k;
    char s[120];
    scanf("%s%d", &s, &k);
    ans = 1;
    now.input(s);
    for (int i = 1; i <= k; i++) {
        INT t = now;
        t.mod10n(i);
        int c = getcircle(t, i);
        if (c < 0) {
            ans = -1;
            break;
        }
        ans.mul(c);
        t = 1;
        for (int j = 0; j < c; j++) {
            t.mul(now);
            t.mod10n(k);
        }
        now = t;
    }
    ans.print();
}