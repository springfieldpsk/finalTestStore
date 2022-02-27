# README

## 太阳高度角与太阳方位角

cpp: sunAngle.cpp

### 太阳高度角与太阳方位角 计算方法

#### 赤道坐标系

时角 $\omega$:

时角是从观测点天球子午圈沿天赤道量至太阳所在时圈的角距离

$$\omega = (T - 12) * 15^{\circ}$$

T 为真太阳时

赤纬角$\delta$:

赤纬角是地球赤道面与太阳和地球中心连接线的夹角

$$\delta = 23.45 \sin(360 \times \frac{284+N}{365})$$

N为积日,即从当年1月1日起开始计算的天数。例如：每年的1月1日为第1日，2月1日为第32日，以此类推。平年的12月31日为第365日，闰年的12月31日为第366日

#### 地平坐标系

太阳高度角 $\alpha _{s}$:

太阳直射光与其观察点所在地平面的夹角

$$ \sin \alpha _{s} = \sin{\varphi}\sin{\delta} + \cos{\varphi}\cos{\delta} \cos \omega $$

$\varphi$为观测者所在地纬度

方位角 $\gamma _{s}$:

太阳直射光线在地平面上的投影线与地平面上正南方向线之间的夹角

$$\sin \gamma _{s} = \frac{\cos \delta \sin \omega}{\cos \alpha_{s}}$$

$$ \cos \gamma _{s} = \frac{\sin \alpha _{s} \sin \varphi - \sin \delta}{\cos \alpha _{s} \cos \varphi}$$

#### 真太阳时

$$ 平太阳时 = 北京时间 \pm 4 min * ( L_{st} - L_{LOC})$$

$L_{LOC}$ 为被测地所在经度, "+"适用于西半球,"-"适用于东半球。$L_{st}$为标准时区经度,北京时间$L_{st}=120$

真太阳时差$\Delta t^{[2]}$:

$$ \Delta t = 0.0028 - 1.9857 \sin \theta + 9.9059 \sin 2 \theta - 7.0924 \cos \theta - 0.6882 cos 2 \theta $$

日角 $\theta$:

$$\theta = 2 \pi t \div 365.2422$$

$$ t = N - N_{0}$$

N为积日, $N_{0}$为标准年

$$N_{0} = K + 0.2422 * (年份 - 标准年) - INT(0.25 * (年份 - 标准年))$$

K是标准年的岁首至春分点的时间，设定标准年为1985年,即K = 79.6764

$$真太阳时 = 北京时间 \pm 4 min * ( L_{st} - L_{LOC}) + \Delta t`$$

[1]王慧,崔连延.太阳高度角和方位角的计算算法[J].电子技术与软件工程,2015(17):167.

[2]王炳忠,刘庚山.日射观测中常用天文参数的再计算[J].太阳能学报,1991(01):27-32.