#include <bits/stdc++.h>
using namespace std;

int main() {
  int c;
  cin >> c;
  while(c--){
    double a,n,h;
    cin >> a >> n >> h;
    double angulo = 360.0/n;
    double aux = n/2.0;
    double segmento = ((a*a)/2.0)*((M_PI*angulo)/180.0 - sin(M_PI/aux));
    double areaSegmento = segmento * h;
    double segmentoTotal = areaSegmento * n;
    cout << setprecision(3) << fixed << segmentoTotal <<endl;
  }
}
