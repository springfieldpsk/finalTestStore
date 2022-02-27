// #pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<double, double> Pd;
typedef pair<ll, ll> pll;
const float PI = acos(-1.0);

float GetSUnTimeDelta(int year){
    const float K = 79.6764; // 标准年的岁首至春分点的时间
    const int standY = 1985; // 标准年
    const float TropicalY = 365.2422; // 实际回归年长度

    time_t now = time(0);
    tm *nowTm = localtime(&now); 
    float N = nowTm->tm_yday + 1; // 积日

    float N0 = K + 0.2422 * (year - standY) - (int)(0.25 * (year - standY)); 
    float t = N - N0;

    float theta = (2 * PI * t) / TropicalY; // 日角
    float deltat = 0.0028 - 1.9857 * sin(theta) + 9.9059 * sin(2 * theta) - 7.0924 * cos(theta) - 0.6882 * cos(2 * theta);

    return deltat;
}

bool GetSunAngle(){

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    //freopen(".out","w",stdout);
#endif
    
    
    return 0;
}