/*
    Using virtual makes the compiler to use just the implemented child classes
*/

#include<iostream>
#include<stdio.h>
using namespace std;

struct X {int x; virtual ~X(){}};
struct Y : virtual X {};
struct Z : virtual X {};

struct W final : Y, Z {}; // 'final' marks the end of the inheritance hierarchy
// struct Aurora : W {}; // wouldn't work

int main()
{
    W p;
    p.x = 45;
    printf("%d\n", p.x);
}