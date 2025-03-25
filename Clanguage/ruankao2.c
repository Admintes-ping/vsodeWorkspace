#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 128

typedef enum { false, true } _bool;

typedef struct {
    char *base;     // 栈的存储空间
    int top;        // 栈顶指针
    int capacity;   // 栈的容量
} STACK;

// 创建栈
_bool createstack(STACK *s) {
    s->base = (char *)malloc(INIT_SIZE * sizeof(char)); // 分配内存
    if (!s->base) return false;
    s->capacity = INIT_SIZE;
    s->top = 0;
    return true;
}

// 判断栈是否为空
_bool empty(STACK *s) {
    return (0 == s->top);
}

// 入栈操作
_bool push(STACK *s, char elem) {
    if (s->top == s->capacity) { // 栈满时，扩容
        int size = s->capacity + s->capacity / 2;
        char *p = (char *)realloc(s->base, size * sizeof(char));
        if (!p) return false;
        s->base = p;
        s->capacity = size;
    }
    s->base[s->top] = elem;
    ++s->top;
    return true;
}

// 出栈操作
void pop(STACK *s) {
    if (s->top) {
        --s->top;
    } else {
        printf("error: stack is empty!\n");
    }
}

// 获取栈顶元素
char top(STACK *s) {
    if (s->top) {
        return s->base[s->top - 1];
    }
    printf("error: stack is empty!\n");
    return '\0'; // 如果栈为空，返回空字符
}

int main() {
    char ch;
    STACK st;

    if (!createstack(&st)) {
        exit(0); // 创建栈失败，退出
    }

    // 读取输入直到遇到 & 或换行
    while (true) {
        ch = getchar();
        if (ch == '&' || ch == '\n' || ch == '\r' || ch == EOF) break;
        if (!push(&st, ch)) { // 入栈失败，退出
            printf("error: stack overflow!\n");
            exit(0);
        }
    }

    if (ch == '&') { // 如果遇到 &
        while (true) {
            ch = getchar();
            if (ch == '\n' || ch == '\r' || ch == EOF) break;
            if (empty(&st) || top(&st) != ch) break; // 如果栈为空或栈顶元素不匹配，退出
            pop(&st); // 出栈
        }
    }

    // 判断栈是否为空
    if ((ch == '\n' || ch == '\r' || ch == EOF) && empty(&st)) {
        printf("The input is a palindrome\n");
    } else {
        printf("The input is not a palindrome\n");
    }

    return 0;
}
