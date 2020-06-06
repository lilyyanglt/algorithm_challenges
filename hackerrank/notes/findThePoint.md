# Find the Point

## Mathematical concepts

> source: https://en.wikipedia.org/wiki/Point_reflection

__point reflection__

- Geometry
- Here's the formula to finding the point reflection (rx, ry) from 2 points

(px, py)
(qx, qy)

```
rx = (2 * qx) - px
ry = (2 * qy) - py

```

## Better solutions for reference
- I am finding that the prepopulated code from hackerrank for reading input and producing output is too verbose, so I've looked at others and see how they do it.

```cpp

#include<stdio.h>

int main()
{
    int t,Px, Py, Qx, Qy;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&Px, &Py, &Qx, &Qy);
        printf("%d %d\n",(2 * Qx) - Px, (2 * Qy) - Py);
    }
    return 0;
}


```
