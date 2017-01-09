#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>

int main(){
int g = 0;
bool b = true;
char a = 'a';
int k = 5;
bool y = false;
char aa = 'b';
char ww = 'k';
bool u = true;
int yy = 5;
printf("g: %d, b: %d, a: %d, k: %d, y: %d,\n aa: %d, ww: %d, u: %d, yy: %d\n\n", &g, &b, &a, &k, &y, &aa, &ww, &u, &yy);
bool x = false;
char xa = 'b';
char xw = 'k';
bool xx = true;
int xy = 5;
printf("x: %d, xa: %d, xw: %d,\n xx: %d, xy: %d\n", &x, &xa, &xw, &xx, &xy);
}
