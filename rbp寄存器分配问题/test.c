/*
在32位中ebp寄存器用来专门存储帧地址，叫做帧指针寄存器。
而在x64中废弃了这一用法，rbp变成了一个通用寄存器。
但gcc中还是倾向生成使用rbp作为帧指针寄存器的代码。
    执行以下指令：
        gcc test.c -o test.o 
        objdump -d test.o > test.dis
在x64中可以不使用rbp作为帧指针寄存器，而是通过确定好整个函数栈需要分配的空间，
然后统一分配出所有空间寄存器，那么栈指针的位置就可以确定下来了。
那么栈上的空间就可以使用栈指针的偏移量进行访问，而不用使用帧指针的地址进行访问。
这样就节省出来了一个通用寄存器rbp。但会使debug变得困难
    执行以下指令
        gcc test.c -o test.o -fomit-frame-pointer
        objdump -d test.o > test.omit_frame_pointer.dis
参考：
https://stackoverflow.com/questions/41912684/what-is-the-purpose-of-the-rbp-register-in-x86-64-assembler
csapp第二版p194 倒数第4行
*/
#include <stdio.h>

void alloc(int i, int j) {
    int z = i + j;
    printf("%d", z);
}

int main() {
    alloc(5,8);
    return 0;
}