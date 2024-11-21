#include<stdio.h>
#define N 5

struct Stack {

    int v[N];
    int t;

    Stack() {
        t = 0;
    }

    bool empty() { // O(1)
        return t == 0;
    }

    bool full() { // O(1)
        return t >= N;
    }

    void push(int value) { // O(1)
        if (full()) {
            printf("Full\n");
            return;
        }
        v[t++] = value;
    }

    void pop() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return;
        }
        t--;
    }

    int top() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return v[t - 1];
    }

};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }

    return 0;
}
