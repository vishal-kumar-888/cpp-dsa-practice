#include <algorithm>
#include <cmath>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = std::max(x1, std::min(xCenter, x2));
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the squared distance between the circle's center and this closest point
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;
        int squaredDistance = (distX * distX) + (distY * distY);
        
        // If the squared distance is <= squared radius, they overlap
        return squaredDistance <= (radius * radius);
    }
};

