# Result

## 執行
```
PS C:\Users\USER\Desktop\系統程式\sp108b\homework\power> gcc jitcallpow.c -o pow
PS C:\Users\USER\Desktop\系統程式\sp108b\homework\power> ./pow
power(2 ,3)=16
```

## 原理
```
PS C:\Users\USER\Desktop\系統程式\sp108b\homework\power> gcc -c power.c
PS C:\Users\USER\Desktop\系統程式\sp108b\homework\power> objdump -d power.o

power.o:     file format pe-i386


Disassembly of section .text:

00000000 <_power>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	83 ec 10             	sub    $0x10,%esp
   6:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%ebp)
   d:	eb 0e                	jmp    1d <_power+0x1d>
   f:	8b 45 fc             	mov    -0x4(%ebp),%eax
  12:	0f af 45 08          	imul   0x8(%ebp),%eax
  16:	89 45 fc             	mov    %eax,-0x4(%ebp)
  19:	83 6d 0c 01          	subl   $0x1,0xc(%ebp)
  1d:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
  21:	79 ec                	jns    f <_power+0xf>
  23:	8b 45 fc             	mov    -0x4(%ebp),%eax
  26:	c9                   	leave  
  27:	c3                   	ret    
```
