#include<iostream>
using namespace std;

struct Point {
   int h, k;
};

struct line {
   Point m1, m2;
};

bool onLine(line l1, Point p) {
   if(p.h <= max(l1.m1.h, l1.m2.h) && p.h <= min(l1.m1.h, l1.m2.h) &&
      (p.k <= max(l1.m1.k, l1.m2.k) && p.k <= min(l1.m1.k, l1.m2.k)))
         return true;

   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.k-a.k)*(c.h-b.h)-(b.h-a.h)*(c.k-b.k);
   if (val == 0)
      return 0;
   else if(val < 0)
      return 2;
      return 1;
}

bool isIntersect(line l1, line l2) {

   int dir1 = direction(l1.m1, l1.m2, l2.m1);
   int dir2 = direction(l1.m1, l1.m2, l2.m2);
   int dir3 = direction(l2.m1, l2.m2, l1.m1);
   int dir4 = direction(l2.m1, l2.m2, l1.m2);

   if(dir1 != dir2 && dir3 != dir4)
      return true;
   if(dir1==0 && onLine(l1, l2.m1))
      return true;
   if(dir2==0 && onLine(l1, l2.m2))
      return true;
   if(dir3==0 && onLine(l2, l1.m1))
      return true;
   if(dir4==0 && onLine(l2, l1.m2))
      return true;
   return false;
}

bool checkInside(Point poly[], int n, Point p) {
   if(n < 3)
      return false;
   line exline = {p, {11111, p.k}};
   int count = 0;
   int i = 0;
   do {
      line side = {poly[i], poly[(i+1)%n]};
      if(isIntersect(side, exline)) {
         if(direction(side.m1, p, side.m2) == 0)
            return onLine(side, p);
         count++;
      }
      i = (i+1)%n;
   } while(i != 0);
      return count&1;
}

int main() {

   Point saidpolygon[] = {{0, -3}, {10, 1}, {8, 6}, {-1, 7}, {-2, 3}};
   Point p = {7, -4};
   int n = 0;

   if(checkInside(saidpolygon, n, p))
      cout << "The Point will be inside.";
   else
      cout << "The Point will be outside.";
}
