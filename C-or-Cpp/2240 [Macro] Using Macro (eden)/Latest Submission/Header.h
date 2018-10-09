#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
#define MAX 100
#define MIN -100
#define max(a,b) a>b?a:b
#define square(a) pow(a,2)
#define e(a,b) a*(pow(10,b))
#define mstr(a) str(a)
#define str(a) #a
#define WARN_IF(a) \
if (a) \
printf ("Warning: "#a"\n"); \

#endif