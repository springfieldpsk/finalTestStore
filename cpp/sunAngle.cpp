// #pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<double, double> Pd;
typedef pair<ll, ll> pll;
const float PI = acos(-1.0);

float GetSUnTimeDelta1(int year,float N){
    const float K = 79.6764; // 标准年的岁首至春分点的时间
    const int standY = 1985; // 标准年
    const float TropicalY = 365.2422; // 实际回归年长度

    float N0 = K + 0.2422 * (year - standY) - (int)(0.25 * (year - standY)); 
    float t = N - N0;

    float theta = (2 * PI * t) / TropicalY; // 日角
    float deltat = 0.0028 - 1.9857 * sin(theta) + 9.9059 * sin(2 * theta) - 7.0924 * cos(theta) - 0.6882 * cos(2 * theta);

    return deltat;
}


float GetSUnTimeDelta2(float N){
    float Q = (2 * PI * N) / 365;

    float deltat = 0.0172 + 0.4281 * cos(Q) - 7.3515 * sin(Q) - 3.3495 * cos( 2 * Q ) - 9.3619 * sin( 2 * Q );
    return deltat;
}

// *******
// LonDir 经度方位 true 为 东经 false 为西经
// Lon 经度 Lat 纬度
void GetSunAngle(float Lon , float Lat , 
                float &SolarHightAngle , 
                float &SolarDirAngle ){
    float TureSolarTime;  // 真太阳时
    float TimeAngle;    // 时角
    float DecAngle;     // 赤纬角

    time_t now = time(0);
    tm *nowTm = localtime(&now); 
    float N = nowTm->tm_yday + 1; // 积日

    DecAngle = 23.45 * sin ( 360 * (284 + N) / 365 );
    
    tm *gmTm = gmtime(&now); 
    float UTCTime = gmTm->tm_hour + gmTm->tm_min * 1.0 / 60;  // 格林尼治时间

    TureSolarTime = UTCTime +  4 * Lon / 60 + GetSUnTimeDelta1( nowTm->tm_year , N );
    TimeAngle = ( TureSolarTime - 12 ) * 15 * PI / 180;

    float LonRad = Lon * PI / 180 ;
    float LatRad = Lat * PI / 180 ;
    SolarHightAngle = asin(sin(LatRad) * sin(DecAngle) + cos(LatRad) * cos(DecAngle) * cos(TimeAngle));
    SolarDirAngle = asin(cos(DecAngle) * sin(TimeAngle) / cos(SolarHightAngle));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    //freopen(".out","w",stdout);
#endif
    
    float SolarHightAngle = 0;
    float SolarDirAngle = 0;

    GetSunAngle(120.181823,35.948664,SolarHightAngle,SolarDirAngle);
    cout<< SolarHightAngle * 180 / PI << ' ' << SolarDirAngle * 180 / PI << endl;
    
    time_t now = time(0);
    tm *nowTm = localtime(&now); 

    cout<< nowTm->tm_hour << ' ' << nowTm->tm_min << endl;
    return 0;
}