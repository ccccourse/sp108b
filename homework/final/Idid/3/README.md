## NOTE
```
在不使用wait()的狀況下希望先執行 父執行
這裡使用了kill()這個指令 來讓父執行先執行
但還是有出現了bug 我原本打算設一個變數來紀錄他們的執行
但因為他們互不影響 所以最後也失敗了
這對我來說這個程式比較難懂
```
```
sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
signum：要操作的信號。
act：要設置的對信號的新處理方式。
oldact：原來對信號的處理方式。
```