class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12) * 30 + minutes * 0.5;
        double m = minutes * 6;
        double d = abs(h - m);
        return d > 180 ? 360 - d : d;
    }
};