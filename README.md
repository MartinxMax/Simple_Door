
支持原创是您给我的最大动力...
# 原理

-基础设备代码程序-

![6AE30VU1ZZ5S010&A7DV1.png](https://image.3001.net/images/20240127/1706359060_65b4f9146f5a6a133ba84.png!small)

-Arduino爆破器程序 or 51爆破器程序-

任意选一个都可以用...

—Arduino带TFT屏幕———

![image.png](https://image.3001.net/images/20240127/1706359134_65b4f95e4f9d396e38c52.png!small)

—51带LCD1602———

![image.png](https://image.3001.net/images/20240127/1706359265_65b4f9e1215f77d75b26a.png!small)

- - -

基础设备的最大密码长度是0x7F，因为有一位作为共地

![image.png](https://image.3001.net/images/20240127/1706362815_65b507bfa5adfd4cc3ab6.png!small)

如果对方需要破解你的门禁,就必须猜解出你的地线在哪一位上..
咱们可以调换线序来混淆电路

![image.png](https://image.3001.net/images/20240127/1706360879_65b5002f1e07670c5ff68.png!small)

![image.png](https://image.3001.net/images/20240127/1706360891_65b5003be4a5907a4ee59.png!small)

# 进行电路混淆提高爆破难度

![image.png](https://image.3001.net/images/20240127/1706363261_65b5097dda11138b51e18.png!small)

| 绿白 | 绿 | 白橙 | 蓝 | 白蓝 | 橙 | 白棕 | 棕 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| P1.0 | P1.1 | P1.2 | P1.3 | P1.4 | P1.5 | P1.6 | GND |
| 1 | 1 | 0(No) | 0(No) | 1 | 0(No) | 0(No) | GND |

那么GND只能和红色1的位置进行二次电路混淆,否则一样会被破解

![image.png](https://image.3001.net/images/20240127/1706363295_65b5099f8b330e373cf7c.png!small)

# 制作基础设备

## 准备材料

1.24V适配器
2.24V电磁阀推杆
3.51单片机
4.以太网接口
5.5V供电电源
6.5V继电器\_高/低电平触发

![image.png](https://image.3001.net/images/20240127/1706358636_65b4f76c15e1526a4241f.png!small)

## 接线原理图

![image.png](https://image.3001.net/images/20240127/1706359782_65b4fbe6df7302ab045a7.png!small)

## 制作密钥网线

我们根据程序中的密钥
![image.png](https://image.3001.net/images/20240127/1706359899_65b4fc5b565f7c501e5ac.png!small)
来制作我们我们的特殊网线

我们需要两头均为协议B或协议A的网线,或者你自己做一个协议都没问题,用协议A或者协议B是为了破解器可以破解我们的设备

![image.png](https://image.3001.net/images/20240127/1706360081_65b4fd117a388d207cb6d.png!small)

![image.png](https://image.3001.net/images/20240127/1706360145_65b4fd5185320e0eb6351.png!small)

剥皮噜

![image.png](https://image.3001.net/images/20240127/1706360250_65b4fdba5e03213f52946.png!small)

切长一点

![image.png](https://image.3001.net/images/20240127/1706360271_65b4fdcf3dd65560f4f95.png!small)

我们这里用直连协议B来进行解锁

![image.png](https://image.3001.net/images/20240127/1706360440_65b4fe780569c5c88e953.png!small)

我们将另一头插入

![image.png](https://image.3001.net/images/20240127/1706360879_65b5002f1e07670c5ff68.png!small)

![image.png](https://image.3001.net/images/20240127/1706360891_65b5003be4a5907a4ee59.png!small)

可以看到网线接线是A协议,也就是说

| 绿白 | 绿 | 白橙 | 蓝 | 白蓝 | 橙 | 白棕 | 棕 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| P1.0 | P1.1 | P1.2 | P1.3 | P1.4 | P1.5 | P1.6 | GND |

我们的密钥按照协议A,整理好线头

那么低位就是绿白->棕,根据密钥0x12

| 绿白 | 绿 | 白橙 | 蓝 | 白蓝 | 橙 | 白棕 | 棕 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| P1.0 | P1.1 | P1.2 | P1.3 | P1.4 | P1.5 | P1.6 | GND |
| 0 | 1 | 0 | 0 | 1 | 0 | 0 | GND |

把0全部和棕色接上就OK噜....

![image.png](https://image.3001.net/images/20240127/1706361947_65b5045b517609b42b421.png!small)

![image.png](https://image.3001.net/images/20240127/1706362261_65b505958c22a975048f0.png!small)

![image.png](https://image.3001.net/images/20240127/1706362223_65b5056f773f54cd51b00.png!small)

![78A84DB3624FC166C29A06B1A5CBE6CA.gif](https://image.3001.net/images/20240127/1706362661_65b50725a317a67e4db67.gif!small)

# 制作破解器
## 准备材料

1.I2C扩展模块
2.TFT显示屏(无触摸屏)
3.Arduino UNO
4.以太网接口
5.5V供电电源

![image.png](https://image.3001.net/images/20240127/1706363995_65b50c5bbc5079ebdd381.png!small)

##  接线图

TFT显示屏的LCD_RST接到Arduino的13脚上.
![image.png](https://image.3001.net/images/20240127/1706364123_65b50cdb4567b683611a9.png!small)
![image.png](https://image.3001.net/images/20240127/1706364632_65b50ed822d5341b71be9.png!small)

## 测试

![image.png](https://image.3001.net/images/20240127/1706364675_65b50f031577aa2e52890.png!small)

![image.png](https://image.3001.net/images/20240127/1706364688_65b50f1020068ee3ae75f.png!small)

该设备会将我们的Payload通过网线口发送出去

(Ps:你必须知道对方是否采用了混淆[必须知道对方地线是哪一根])
![image.png](https://image.3001.net/images/20240127/1706365165_65b510ed709e764605cd6.png!small)

![image.png](https://image.3001.net/images/20240127/1706365183_65b510ff082e75a98f773.png!small)
