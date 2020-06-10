# MID
```
我的編譯器擴充自老師的課堂範例， if, goto, for 語法則是新加入的。
if,goto 是我 100% 原創的。
for 有參考 http://ccckmit.wikidot.com/cd:for
參考老師的範例之後，我讀懂了，於是完全靠自己寫出 if, goto, for 擴充部分。
對這個編譯器原始碼我完全可以理解。

在程式中寫一個STS() 是給for()的判斷句
```
## for test mode
```
PS C:\Users\USER\Desktop\系統程式\sp108b\homework\mid> ./compiler test/for.c -ir -run 
=======irDump()==========
00: t1 = 0
01: j = t1
02: t1 = 0
03: i = t1
04: (L1)
05: t2 = i
06: t3 = 2
07: t4 = t2 < t3
08: t1 = i
09: t2 = 1
10: t3 = t1 + t2
11: i = t3
12: if not t4 goto L2
13: t1 = j
14: t2 = 1
15: t3 = t1 + t2
16: j = t3
17: if t4 goto L1
18: (L2)
===================irRun()=======================
00: t1 = 0 (0)
01: j = t1 (0)
02: t1 = 0 (0)
03: i = t1 (0)
04: (L1) (4)
05: t2 = i (0)
06: t3 = 2 (2)
07: t4 = t2 < t3 (1)
08: t1 = i (0)
09: t2 = 1 (1)
10: t3 = t1 + t2 (1)
11: i = t3 (1)
12: ifnot t4 (1)  -- fail
13: t1 = j (0)
14: t2 = 1 (1)
15: t3 = t1 + t2 (1)
16: j = t3 (1)
17: if t4 (1) goto L1 (4)
04: (L1) (4)
05: t2 = i (1)
06: t3 = 2 (2)
07: t4 = t2 < t3 (1)
08: t1 = i (1)
09: t2 = 1 (1)
10: t3 = t1 + t2 (2)
11: i = t3 (2)
12: ifnot t4 (1)  -- fail
13: t1 = j (1)
14: t2 = 1 (1)
15: t3 = t1 + t2 (2)
16: j = t3 (2)
17: if t4 (1) goto L1 (4)
04: (L1) (4)
05: t2 = i (2)
06: t3 = 2 (2)
07: t4 = t2 < t3 (0)
08: t1 = i (2)
09: t2 = 1 (1)
10: t3 = t1 + t2 (3)
11: i = t3 (3)
12: ifnot t4 (0) goto L2 (18)
18: (L2) (18)
```

## goto test mod
```
PS C:\Users\USER\Desktop\系統程式\sp108b\homework\mid> ./compiler test/goto.c -ir -run
=======irDump()==========
00: t1 = 0
01: i = t1
02: t1 = 0
05: (L1)
06: t1 = j
07: t2 = 1
08: t3 = t1 + t2
09: j = t3
===================irRun()=======================
00: t1 = 0 (0)
01: i = t1 (0)
02: t1 = 0 (0)
03: j = t1 (0)
04: goto L1 (5)
05: (L1) (5)
06: t1 = j (0)
07: t2 = 1 (1)
08: t3 = t1 + t2 (1)
09: j = t3 (1)
```