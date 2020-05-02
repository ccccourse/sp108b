#include<stdio.h>

unsigned char powerCode[] = {
    0x55,                   	              //push   %ebp
    0x89, 0xe5,                	              //mov    %esp,%ebp
    0x83, 0xec, 0x10,             	          //sub    $0x10,%esp
    0xc7, 0x45, 0xfc, 0x01, 0x00, 0x00, 0x00, //movl   $0x1,-0x4(%ebp)
    0xeb, 0x0e,                	              //jmp    1d <_power+0x1d>
    0x8b, 0x45, 0xfc,             	          //mov    -0x4(%ebp),%eax
    0x0f, 0xaf, 0x45, 0x08,          	      //imul   0x8(%ebp),%eax
    0x89, 0x45, 0xfc,                         //mov    %eax,-0x4(%ebp)
    0x83, 0x6d, 0x0c, 0x01,          	      //subl   $0x1,0xc(%ebp)
    0x83, 0x7d, 0x0c, 0x00,                   //cmpl   $0x0,0xc(%ebp)
    0x79, 0xec,                               //jns    f <_power+0xf>
    0x8b, 0x45, 0xfc,             	          //mov    -0x4(%ebp),%eax
    0xc9,                   	              //leave  
    0xc3,                   	              //ret 
};

int (*power)(int a,int b);

int main() 
{
    power = (int (*)(int, int)) powerCode;
    printf("power(2 ,3)=%d\n", power(2,3));
}