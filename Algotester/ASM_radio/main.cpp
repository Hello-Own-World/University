#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ld = long double;
ld eps;

ld find_angle(ld x, ld y) {
    ld ang = atan(y / x);
    if (x != 0 && y != 0) {
        if (x > 0 && y > 0) {
            ang += 0;
        } else if (x < 0 && y > 0) {
            ang += M_PI;
        } else if (x < 0 && y < 0) {
            ang += M_PI;
        } else if (x > 0 && y < 0) {
            ang += 2 * M_PI;
        }
    } else {
        if (x == 0 && y < 0) {
            return (M_PI / 2) * 3;
        } else if (x == 0 && y > 0) {
            return M_PI / 2;
        } else if (x > 0 && y == 0) {
            return 0;
        } else if (x < 0 && y == 0) {
            return M_PI;
        }
    }
    return ang;
}

struct dot {
    ld x{}, y{}, angle{}, seg{};
    bool active = true;

    dot(ld x, ld y) : x(x), y(y) {
        angle = find_angle(x, y);
    };

    dot(ld x, ld y, ld seg) : x(x), y(y), seg(seg) {
        angle = find_angle(x, y);
    };
    dot() = default;
    static ld dist_dots(dot p1, dot p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    bool operator!=(dot d1) const {
        if (abs(x - d1.x) > eps ||
            abs(y - d1.y) > eps) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(dot d) const {
        if (angle < d.angle) {
            return true;
        } else {
            return false;
        }
    }
};

struct equ {
    ld a, b, c;
    static equ equ_2dots(dot a1, dot a2) {
        return {a2.y - a1.y, a1.x - a2.x, a2.x * a1.y - a1.x * a2.y};
    };
};

struct segment {
    dot a1, a2;
    segment(dot a1, dot a2) : a1(a1), a2(a2) {}
    equ line = equ::equ_2dots(a1, a2);
    vector<dot> dots;
    void add_dot(dot a3) {
        dots.emplace_back(a3);
    }
};

dot intersect_2lines(equ l1, equ l2) {
    return {(l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l2.a * l1.b),
            (l1.c * l2.a - l2.c * l1.a) / (l1.a * l2.b - l2.a * l1.b)};
}

bool belongs_to_segm(dot intersec, const segment &segm) {
    bool f1 = false, f2 = false;
    if (segm.a1.x <= intersec.x && intersec.x <= segm.a2.x || segm.a2.x <= intersec.x && intersec.x <= segm.a1.x) {
        f1 = true;
    }
    if (segm.a1.y <= intersec.y && intersec.y <= segm.a2.y || segm.a2.y <= intersec.y && intersec.y <= segm.a1.y) {
        f2 = true;
    }
    if (f1 && f2) {
        return true;
    } else {
        return false;
    }
}

bool point_quarter_match(dot temp2, dot temp) {
    if (temp2.x != 0 && temp2.y != 0) {
        if (temp2.x > 0 && temp2.y > 0 && temp.x > 0 && temp.y > 0) {
            return true;
        } else if (temp2.x < 0 && temp2.y > 0 && temp.x < 0 && temp.y > 0) {
            return true;
        } else if (temp2.x < 0 && temp2.y < 0 && temp.x < 0 && temp.y < 0) {
            return true;
        } else if (temp2.x > 0 && temp2.y < 0 && temp.x > 0 && temp.y < 0) {
            return true;
        } else {
            return false;
        }
    } else if (temp2.x == 0 && temp2.y > 0 && temp.x == 0 && temp.y > 0) {
        return true;
    } else if (temp2.x == 0 && temp2.y < 0 && temp.x == 0 && temp.y < 0) {
        return true;
    } else if (temp2.x > 0 && temp2.y == 0 && temp.x > 0 && temp.y == 0) {
        return true;
    } else if (temp2.x < 0 && temp2.y == 0 && temp.x < 0 && temp.y == 0) {
        return true;
    } else {
        return false;
    }
}

pair<dot, dot> dot_on_circle(equ e, ld r) {
    ld x1, y1, x2, y2;
    y1 = ((-1 * e.b * e.c) + sqrt(e.a * e.a * (r * r * e.a * e.a + r * r * e.b * e.b - e.c * e.c))) /
         ((e.a * e.a) + (e.b * e.b));
    y2 = ((-1 * e.b * e.c) - sqrt(e.a * e.a * (r * r * e.a * e.a + r * r * e.b * e.b - e.c * e.c))) /
         ((e.a * e.a) + (e.b * e.b));
    x1 = (((-1 * e.b * y1) - e.c) / e.a);
    x2 = (((-1 * e.b * y2) - e.c) / e.a);
    return {dot(x1, y1), dot(x2, y2)};
}

ld dstc(dot d) {
    return dot::dist_dots({0, 0}, d);
}

void dot_check(vector<segment> &segments, dot &center, dot &temp2, ld r) {
    if (dstc(temp2) <= r || abs(dstc(temp2) - r) < eps) {
        bool flag1 = false;
        dot last_temp;
        int last_j;
        ld last_length;
        for (int j = 0; j < segments.size(); ++j) {
            dot temp = intersect_2lines(segments[j].line, equ::equ_2dots(center, temp2));
            if (belongs_to_segm(temp, segments[j]) && point_quarter_match(temp2, temp)) {
                if (dot::dist_dots(center, temp) < dot::dist_dots(center, temp2)) {
                    if (temp != segments[j].a1 && temp != segments[j].a2) {
                        temp2.active = false;
                        return;
                    }
                } else if (dot::dist_dots(center, temp) == dot::dist_dots(center, temp2)) {//ignore sides of segment
                    segments[j].add_dot(temp2);
                } else {
                    if (!flag1) {
                        last_temp = temp;
                        last_j = j;
                        last_length = dot::dist_dots(center, temp);
                        flag1 = true;
                    } else {
                        if (dot::dist_dots(center, temp) < last_length) {
                            last_temp = temp;
                            last_j = j;
                            last_length = dot::dist_dots(center, temp);
                        }
                    }
                }
            }
        }
        if (flag1 && last_temp != segments[last_j].a1 && last_temp != segments[last_j].a2) {
            segments[last_j].add_dot(last_temp);
        }
    } else {
        temp2.active = false;
    }
}

void is_active(vector<segment> &segments, dot &center, dot &temp2, ld r) {
    if (dstc(temp2) <= r || abs(dstc(temp2) - r) < eps) {
        for (int j = 0; j < segments.size(); ++j) {
            dot temp = intersect_2lines(segments[j].line, equ::equ_2dots(center, temp2));
            if (belongs_to_segm(temp, segments[j]) && point_quarter_match(temp2, temp)) {
                if (dot::dist_dots(center, temp) < dot::dist_dots(center, temp2)) {
                    if (temp != segments[j].a1 && temp != segments[j].a2 && temp != temp2) {
                        temp2.active = false;
                        return;
                    }
                }
            }
        }
    } else {
        temp2.active = false;
    }
}

bool is_active_b(vector<segment> &segments, dot &center, dot temp2, ld r) {
    if (dstc(temp2) <= r || abs(dstc(temp2) - r) < eps) {
        for (int j = 0; j < segments.size(); ++j) {
            dot temp = intersect_2lines(segments[j].line, equ::equ_2dots(center, temp2));
            if (belongs_to_segm(temp, segments[j]) && point_quarter_match(temp2, temp)) {
                if (dot::dist_dots(center, temp) < dot::dist_dots(center, temp2) &&
                    abs(dot::dist_dots(center, temp) - dot::dist_dots(center, temp2)) > eps) {
                    if (temp != segments[j].a1 && temp != segments[j].a2) {
                        return false;
                    }
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

dot mid_p(dot a, dot b) {
    return {(a.x + b.x) / 2, (a.y + b.y) / 2};
}

ld find_area_3dots(dot a, dot b, dot c) {
    return abs((b.x * a.y - a.x * b.y) + (c.x * b.y - b.x * c.y) + (a.x * c.y - c.x * a.y)) / 2;
}

int main() {
    ld n, r;
    eps = 1e-3;
    vector<segment> segments;
    dot center{0, 0};
    cin >> r >> n;
    if (n == 0) {
        cout << fixed << setprecision(3) << M_PI * r * r;
        return 0;
    }
    {
        ld a, b, c, d;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c >> d;
            dot aa = dot(a, b, i);
            dot bb = dot(c, d, i);
            if (aa.angle < bb.angle) {
                segments.emplace_back(aa, bb);
            } else {
                segments.emplace_back(bb, aa);
            }
        }
    }
    for (int k = 0; k < segments.size(); ++k) {
        dot &temp1 = segments[k].a1;
        dot_check(segments, center, temp1, r);
        dot &temp2 = segments[k].a2;
        dot_check(segments, center, temp2, r);
        pair<dot, dot> t1;
        t1 = dot_on_circle(segments[k].line, r);
        if (belongs_to_segm(t1.first, segments[k])) {
            is_active(segments, center, t1.first, r);
        } else {
            t1.first.active = false;
        }
        if (belongs_to_segm(t1.second, segments[k])) {
            is_active(segments, center, t1.second, r);
        } else {
            t1.second.active = false;
        }
        if (t1.first.active) {
            segments[k].dots.push_back(t1.first);
        }
        if (t1.second.active) {
            segments[k].dots.push_back(t1.second);
        }
    }
    ld angle = 0;
    ld sum = 0;
    for (int i = 0; i < segments.size(); ++i) {
        std::sort(segments[i].dots.begin(), segments[i].dots.end());
        if (abs(segments[i].a2.angle - segments[i].a1.angle) > M_PI) {
            for (int j = 0; j < segments[i].dots.size(); ++j) {
                if (segments[i].dots[j].angle < M_PI) {
                    segments[i].dots[j].angle += 2 * M_PI;
                }
            }
        }
        std::sort(segments[i].dots.begin(), segments[i].dots.end());
        if (segments[i].dots.size() > 1) {
            for (int j = 0; j < segments[i].dots.size() - 1; ++j) {
                if (segments[i].dots[j].active && segments[i].dots[j + 1].active &&
                    is_active_b(segments, center, mid_p(segments[i].dots[j], segments[i].dots[j + 1]), r)) {
                    sum += find_area_3dots(segments[i].dots[j], segments[i].dots[j + 1], center);
                    ld an1 = segments[i].dots[j].angle, an2 = segments[i].dots[j + 1].angle;
                    if (abs(an1 - an2) > M_PI) {
                        angle += (min(an1, an2) + 2 * M_PI - max(an1, an2));
                        continue;
                    }
                    if (an2 < an1) {
                        cout << "fuck";
                    }
                    angle += an2 - an1;
                }
            }
        }
    }
    sum += r * r * (2 * M_PI - angle) / 2;
    cout << fixed << setprecision(3) << sum;
    return 0;
}
/*
5 2
 -1 0 0 1
 0 -5 5 0

 5 2
 -1 0 0 1
 5 0 0 -5

 ans 52.270


 5 2
 -1 -1 -1 1
 1 -1 1 1

ans 41.270

 9 14
 -8 2 -2 8
 -6 3 -5 4
 -4 5 -3 6
 2 5 5 3
 0 3 2 3
 3 2 3 1
 -1 -2 1 -2
 -3 0 -2 -2
 -3 -2 -1 -3
 -1 -4 3 -5
  -1 -5 -5 0
 -3 -6 3 -6
 -4 -6 -6 1
 4 0 7 0

ans 116.795

0 partitions 4 segments

 5 4
  -3 1 1 2
  -4 2 -2 -4
  1 4 3 -2
  -2 -3 4 -2

  ans 23.672

1 dot on contour

 5 4
 -2 2 1 2
 1 3 2 -2
 -2 -3 3 -2
 -2 -4 -3 3

 ans 19.786

 3 dots on circle
 5 4
 -1 1 1 1
 2 2 2 -2
 -2 -3 3 -3
 -3 3 -2 -4

 ans 20.441

0.1 0
0.0314159

 0.1 1

0.0314159

 5 0

78.540

 1 segment out of circle completely
 5 1
 10 0 10 10

 5 1
 5 0 7 0

 78.540

 1 segment with sides outside of circle but intersects circle
 5 1
-5 4 1 -7
 */