# [STL] Delivery (eden)

## Description

快递公司在运送货物的时候，会通过机器扫描得到货物信息。

但由于网络问题或重复扫描等问题，会产生冗余信息。

现在需要根据接收到的信息，进行整理并按时间排序，去除掉多余信息。

信息方式：

```
YYYY/MM/DD-HH:mm:ss|快递信息
```

保留某“快递信息”最早记录。

按时间顺序进行排序。

月：1-12

日：1-30

时：0-23

分、秒：0-59

输出格式

```
YYYY/MM/DD-HH:mm:ss : 快递信息
```

## Hint
1. map中key为唯一的。
2. 可能用到的函数：
`std::map::find`和string相关函数：find_first_of、substr、compare等

## Sample Input
```
4
2016/01/04-12:12:12|out
2016/01/04-12:23:43|get
2016/01/04-12:12:12|get
2016/01/04-12:10:42|out

```

## Sample Output
```
2016/01/04-12:10:42 : out
2016/01/04-12:12:12 : get

```