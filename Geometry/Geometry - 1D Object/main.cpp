#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

double DEG_to_RAD(double d) { return d*PI / 180.0; }
double RAD_to_DEG(double r) { return r*180.0 / PI; }

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        // first x and second y
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);
    return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS)
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    else
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x),
        l.b = 1.0,
        l.c = -(double)(l.a * p1.x) - p1.y;
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;
    l.b = -1;
    l.c = -((l.a * p.x) + (l.b * p.y));
}

void closestPoint(line l, point p, point &ans) {
    line perpendicular;
    if (fabs(l.b) < EPS) {
        ans.x = -(l.c);
        ans.y = p.y;
        return;
    }
    if (fabs(l.a) < EPS) {
        ans.x = p.x;
        ans.y = -(l.c);
        return;
    }
    pointSlopeToLine(p, 1 / l.a, perpendicular);
    areIntersect(l, perpendicular, ans);
}

void reflectionPoint(line l, point p, point &ans) {
    point b;
    closestPoint(l, p, b);
    vec v = toVec(p, b);
    ans = translate(translate(p, v), v);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(a, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

int main() {
    /*
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    */

    point P1, P2, P3(0, 1); // note that both P1 and P2 are (0.00, 0.00)
    printf("%d\n", P1 == P2);                                    // true
    printf("%d\n", P1 == P3);                                   // false

    vector<point> P;
    P.push_back(point(2, 2));
    P.push_back(point(4, 3));
    P.push_back(point(2, 4));
    P.push_back(point(6, 6));
    P.push_back(point(2, 6));
    P.push_back(point(6, 5));

    // sorting points demo
    sort(P.begin(), P.end());
    for (int i = 0; i < (int)P.size(); i++)
        printf("(%.2lf, %.2lf)\n", P[i].x, P[i].y);

    // rearrange the points as shown in the diagram below
    P.clear();
    P.push_back(point(2, 2));
    P.push_back(point(4, 3));
    P.push_back(point(2, 4));
    P.push_back(point(6, 6));
    P.push_back(point(2, 6));
    P.push_back(point(6, 5));
    P.push_back(point(8, 6));

    // translation
    point A(2.0, 2.0);
    point B(4.0, 3.0);
    vec v = toVec(A, B); // imagine there is an arrow from A to B (see the diagram above)
    point C(3.0, 2.0);
    point D = translate(C, v); // D will be located in coordinate (3.0 + 2.0, 2.0 + 1.0) = (5.0, 3.0)
    printf("D = (%.2lf, %.2lf)\n", D.x, D.y);
    point E = translate(C, scale(v, 0.5)); // E will be located in coordinate (3.0 + 1/2 * 2.0, 2.0 + 1/2 * 1.0) = (4.0, 2.5)
    printf("E = (%.2lf, %.2lf)\n", E.x, E.y);

    // rotation
    printf("B = (%.2lf, %.2lf)\n", B.x, B.y); // B = (4.0, 3.0)
    point F = rotate(B, 90); // rotate B by 90 degrees COUNTER clockwise, F = (-3.0, 4.0)
    printf("F = (%.2lf, %.2lf)\n", F.x, F.y);
    point G = rotate(B, 180); // rotate B by 180 degrees COUNTER clockwise, G = (-4.0, -3.0)
    printf("G = (%.2lf, %.2lf)\n", G.x, G.y);

    double d = dist(P[0], P[5]);
    printf("Euclidean distance between P[0] and P[5] = %.2lf\n", d); // should be 5.000

    // line equations
    line l1, l2, l3, l4;
    pointsToLine(P[0], P[1], l1);
    printf("%.2lf * x + %.2lf * y + %.2lf = 0.00\n", l1.a, l1.b, l1.c); // should be -0.50 * x + 1.00 * y - 1.00 = 0.00

    pointsToLine(P[0], P[2], l2); // a vertical line, not a problem in "ax + by + c = 0" representation
    printf("%.2lf * x + %.2lf * y + %.2lf = 0.00\n", l2.a, l2.b, l2.c); // should be 1.00 * x + 0.00 * y - 2.00 = 0.00

    // parallel, same, and line intersection tests
    pointsToLine(P[2], P[3], l3);
    printf("l1 & l2 are parallel? %d\n", areParallel(l1, l2)); // no
    printf("l1 & l3 are parallel? %d\n", areParallel(l1, l3)); // yes, l1 (P[0]-P[1]) and l3 (P[2]-P[3]) are parallel

    pointsToLine(P[2], P[4], l4);
    printf("l1 & l2 are the same? %d\n", areSame(l1, l2)); // no
    printf("l2 & l4 are the same? %d\n", areSame(l2, l4)); // yes, l2 (P[0]-P[2]) and l4 (P[2]-P[4]) are the same line (note, they are two different line segments, but same line)

    point p12;
    bool res = areIntersect(l1, l2, p12); // yes, l1 (P[0]-P[1]) and l2 (P[0]-P[2]) are intersect at (2.0, 2.0)
    printf("l1 & l2 are intersect? %d, at (%.2lf, %.2lf)\n", res, p12.x, p12.y);

    // other distances
    point ans;
    d = distToLine(P[0], P[2], P[3], ans);
    printf("Closest point from P[0] to line         (P[2]-P[3]): (%.2lf, %.2lf), dist = %.2lf\n", ans.x, ans.y, d);
    closestPoint(l3, P[0], ans);
    printf("Closest point from P[0] to line V2      (P[2]-P[3]): (%.2lf, %.2lf), dist = %.2lf\n", ans.x, ans.y, dist(P[0], ans));

    d = distToLineSegment(P[0], P[2], P[3], ans);
    printf("Closest point from P[0] to line SEGMENT (P[2]-P[3]): (%.2lf, %.2lf), dist = %.2lf\n", ans.x, ans.y, d); // closer to A (or P[2]) = (2.00, 4.00)
    d = distToLineSegment(P[1], P[2], P[3], ans);
    printf("Closest point from P[1] to line SEGMENT (P[2]-P[3]): (%.2lf, %.2lf), dist = %.2lf\n", ans.x, ans.y, d); // closer to midway between AB = (3.20, 4.60)
    d = distToLineSegment(P[6], P[2], P[3], ans);
    printf("Closest point from P[6] to line SEGMENT (P[2]-P[3]): (%.2lf, %.2lf), dist = %.2lf\n", ans.x, ans.y, d); // closer to B (or P[3]) = (6.00, 6.00)

    reflectionPoint(l4, P[1], ans);
    printf("Reflection point from P[1] to line      (P[2]-P[4]): (%.2lf, %.2lf)\n", ans.x, ans.y); // should be (0.00, 3.00)

    printf("Angle P[0]-P[4]-P[3] = %.2lf\n", RAD_to_DEG(angle(P[0], P[4], P[3]))); // 90 degrees
    printf("Angle P[0]-P[2]-P[1] = %.2lf\n", RAD_to_DEG(angle(P[0], P[2], P[1]))); // 63.43 degrees
    printf("Angle P[4]-P[3]-P[6] = %.2lf\n", RAD_to_DEG(angle(P[4], P[3], P[6]))); // 180 degrees

    printf("P[0], P[2], P[3] form A left turn? %d\n", ccw(P[0], P[2], P[3])); // no
    printf("P[0], P[3], P[2] form A left turn? %d\n", ccw(P[0], P[3], P[2])); // yes

    printf("P[0], P[2], P[3] are collinear? %d\n", collinear(P[0], P[2], P[3])); // no
    printf("P[0], P[2], P[4] are collinear? %d\n", collinear(P[0], P[2], P[4])); // yes

    point p(3, 7), q(11, 13), r(35, 30); // collinear if r(35, 31)
    printf("r is on the %s of line p-r\n", ccw(p, q, r) ? "left" : "right"); // right

    return 0;
}
