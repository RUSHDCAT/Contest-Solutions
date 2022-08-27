# 2011 ACM-ICPC World Finals

## E: Coffee Central

**easy**: just 2d prefix sum query.

complexity $O(n*m*q)$

## G: Magic Sticks

**medium-hard**: need some insight.

* Two adjacent polygons can be merged into a bigger one, which will yield a better solution.
* How to build a polygon by some sticks to maximize the area ? The ituition tell us that just put these joints on a circle.
* We can use binary search to calculate the radius, but take care, there are 2 cases(whether the centre on the circle is in polygon).
* Another insight is if use all sticks is not advisible, we can discard the stick whose length is only maximum in all sticks.

## J: Pyramids

**easy**

An easy dp problem, just implement it carefully.

## K: Trash Removal

**easy**: an easy geometry problem.

* The wall at one side must be concide with 2 points, otherwise we can deduct the answer
* just enumerate 2 points i, j, all remains point must be at the same side of vector, a[i]->a[j], then enumerate point k and calculate the maximum distance.
* minimize it！

