#include <bits/stdc++.h>
using namespace std;
ifstream in("palat.in");
ofstream out("palat.out");
#define cin in
#define cout out
int n, m, mat[1010][1010], minim = 10000001;
char cmat[1010][1010];
int ql[1000001], qc[1000001];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int main() {
      cin >> n >> m;
      int contor = 1, prima = 0;
      for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                  cin >> cmat[i][j];
                  if (cmat[i][j] == '_') mat[i][j] = 0;
                  else if (cmat[i][j] == 'I')  mat[i][j] = 1, prima++, ql[prima] = i, qc[prima] = j;
            }
      while (contor <= prima) {
            int i = ql[contor], j = qc[contor];
            for (int v = 0; v < 4; v++) {
                  int ii = i + dx[v], jj = j + dy[v];
                  if (ii > 0 && jj > 0 && jj <= m && ii <= n && mat[ii][jj] == 0 && cmat[ii][jj] != 'Z')
                        prima++, ql[prima] = ii, qc[prima] = jj, mat[ii][jj] = mat[i][j] + 1;
            }
            contor++;
      } int xminim, yminim;
      for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                  if (mat[i][j] > 0 && cmat[i][j] == 'F' && mat[i][j] <= minim)
                        minim = mat[i][j], xminim = i, yminim = j;
      cout << xminim << " " << yminim;
      return 0;
}