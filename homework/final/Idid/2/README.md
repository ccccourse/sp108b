## NOTE
```
這個程式裡使用了open()以及write()這兩個指令
目的在於測試如果新開一個檔案的話 父行程與子行程都去寫入那個檔案的話會發生甚麼事
結果只要是後執行的都會覆蓋過去 並不會像1一樣2個都寫進去
```
```
https://blog.jaycetyle.com/2018/12/linux-fd-open-close/
open(const char *name, int flags, mode_t mode)
O_CREAT: 如果指定的檔案不存在，就建立一個
O_WRONLY: 以唯寫模式開啟
O_TRUNC: 若開啟的檔案存在且是一般檔案，開啟後就將其截短成長度為 0
S_IRWXU: S_IRUSR | S_IWUSR | S_IXUSR

https://blog.xuite.net/deskwoods/pc/11098842-%5BC%5Dwrite%E7%94%A8%E6%B3%95
write(int, const void*, unsigned int)
在呼叫write()時傳入那個整數為第一個參數
第二參數是個指標,指向你要寫的資料的起頭.第三參數是個整數,代表你要寫多少個bytes
```