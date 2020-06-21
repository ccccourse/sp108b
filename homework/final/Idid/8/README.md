## NOTE 
```
這個程式使用了pipe()這個指令
大概知道他在做什麼 但對於他在寫甚麼還是有點不大懂
```

```
http://burweisnote.blogspot.com/2017/10/pipe.html
http://hugedream.blogspot.com/2009/12/pipe.html
pipe(int pipefd[2])
pipefd[0]代表的是pipe的讀取端，pipefd[1]則是pipe的寫入端

https://blog.jaycetyle.com/2019/01/linux-read-write/
read(int fd, void *buf, size_t len)
系統呼叫會從 fd 所參照檔案的當前位置讀取 len 個位元組到 buf
```