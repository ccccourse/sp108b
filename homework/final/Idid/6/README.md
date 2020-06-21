## NOTE 
```
這裡使用了waitpid()來取代上一個程式中的wait()
waitpid()相比wait()多了2個參數 因此waitpid()會有比較多的功能
```
```
https://b0lv42.github.io/2017/03/23/linux%E7%9A%84fork(),waitpid()%E5%8F%8Await()%E7%9A%84%E7%94%A8%E6%B3%95/
https://www.cntofu.com/book/46/linux_system/linuxxi_tong_bian_cheng_zhi_jin_cheng_ff08_liu_ff0.md
waitpid(pid_t pid,int * status,int options)
status:如果不是空，會把狀態信息寫到它指向的位置，與wait一樣
options:允許改變waitpid的行為，最有用的一個選項是WNOHANG,它的作用是防止waitpid把調用者的執行掛起
```