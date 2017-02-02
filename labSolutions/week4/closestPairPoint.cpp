// #include<bits/stdc++.h>
// using namespace std;

// typedef struct point{
// int x;
// int y;
// }point;


// point closepoint1,closepoint2;

// int compareX(const void* a, const void* b)
// { point *p1 = (point *)a, *p2 = (point *)b;  
//   return p1->x - p2->x; 
// }

// int compareY(const void* a, const void* b)
// { point *p1 = (point *)a, *p2 = (point *)b;
//   return p1->y - p2->y;
// }

// float min(float x, float y)
// { return (x<y)? x : y;
// }

// int dist(point p1, point p2)
// { return sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2)); }

// float stripclose(point s[],int n,float d)
// { float min = d;
//   qsort(s,n,sizeof(point),compareY);
//   for(int i=0;i<n;i++)
//     for(int j=i+1;j<n&&(s[j].y - s[i].y)<min; j++)
//       if(dist(s[i],s[j])<min)
//         { min = dist(s[i],s[j]);
//           closepoint1 = s[i];
// 	  closepoint2 = s[j];
//         }
//   return min;
// }
 

// float closest(point p[],int n)
// { int fh = n/2;
//   int sh = n-n/2;
//   point mid = p[fh];
//   float df = closest(p,fh);
//   float ds = closest(p+fh,sh);
//   float d = min(df,ds);
//   point s[n];
//   int j=0;
//   for(int i=0;i<n;i++)
//   { if(p[i].x - mid.x < d)
//       { s[j] = p[i];j++; }
//   }
//   cout<<"D IS "<<d;
//   return min(d,stripclose(s,j,d));
// }



// int main()
// { int n;
//   point p[100];
//   cin>>n;
//   for(int i=0;i<n;i++)
//      cin>>p[i].x>>p[i].y;

//   qsort(p,n,sizeof(point),compareX);
  
//       /* for(int i=0;i<n;i++)
//      cout<<p[i].x<<" "<<p[i].y<<endl;*/
//  cout<< closest(p,n);
//   return 0;
// }

// A divide and conquer program in C/C++ to find the smallest distance from a
// given set of points.
 
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
 
// A structure to represent a Point in 2D plane
struct Point
{
    int x, y;
}closepoint1,closepoint2;
 
/* Following two functions are needed for library function qsort().
   Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
 
// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 
// A utility function to find the distance between two points
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                { min = dist(P[i], P[j]);
                 closepoint1 = P[i];
                 closepoint2 = P[j];
                }
    return min;
}
 
// A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}
 
 
// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
 
    qsort(strip, size, sizeof(Point), compareY); 
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
               { min = dist(strip[i], strip[j]);
                closepoint1 = strip[i];
                closepoint2 = strip[j];
    //             printf(" closepoint1 %d  %d",closepoint1.x,closepoint1.y);
    // printf(" closepoint2  %d  %d",closepoint2.x,closepoint2.y);
               } 
 
    return min;
}
 
// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);
 
    // Find the middle point
    int mid = n/2;
    Point midPoint = P[mid];
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
 
    // Find the smaller of two distances
    float d = min(dl, dr);
 
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}
 
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
 
    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, n);
}
 
// Driver program to test above functions
int main()
{   int n;
    Point P[100];
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d %d",&P[i].x,&P[i].y);

    //Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    //int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
    // printf(" closepoint1 %d  %d",closepoint1.x,closepoint1.y);
    // printf(" closepoint2  %d  %d",closepoint2.x,closepoint2.y);
    return 0;
}