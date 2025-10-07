/*
    Welcome to the PC-lint Plus interactive demo.
    Press the 'Run' button above to analyze the sample code in this
    text area using PC-lint Plus. Messages will be displayed under
    the corresponding line. The 'Clear' button will hide these messages.

    You can enter your own sample code to evaluate PC-lint Plus.
    The options above can be used to choose whether to use C or C++ and
    to enable optional features such as MISRA rule enforcement.

    Note that MISRA support should be used with the matching language.
    E.g. if using MISRA C 2012 the language (which defaults to C++17)
    should be changed to C99 or C11.
*/

#include <math.h>
#include <stdio.h>

/* Library Function Semantics */
/* Floating Point Value Tracking */

void cr() {
    r(42);   
}
void r(double x) {
    printf("%d", acos(x));
}

/* Queries and Metrics - custom messages (see configuration pane) */
typedef int INT;
typedef int INT_t;
void foo(INT x, INT_t y) {
       if (x == 1) { /* ... */ }
       if (1 == x) { /* ... */ }
       if (x == y) { /* ... */ }
}

/* User-defined metrics (see configuration pane) */
struct X { };
struct Y : private X { };
struct Z : private Y { };
struct W : private Z { };

/* Value Tracking */
int f(void);
int g() {
    return f();   
}
int f() {
    static int x = f();
    return x++;
}

/* Precision Bit Tracking */
void z(char c1, char c2) {
    if ( (c1 & 13) + (c2 & 8) == 6 ) { }
}

/* Value Tracking */
int w(int a) {
    int* p = new int;
    return 5 / a;
}
int q(int b, int c) {
    return w(0) + c + sizeof(W);
}
