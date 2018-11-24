/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        if (!image.size()) return image;
        m = image.size();
        n = image[0].size();
        oldColor = image[sr][sc];
        newColor_t = newColor;
        bfs(image, sr, sc);
        return image;
    }
private:
    int oldColor;
    int newColor_t;
    int m;
    int n;
    bool bfs(vector<vector<int> >& image, int sr, int sc) {
        if (image[sr][sc] == newColor_t) return false;
        if (image[sr][sc] == oldColor) {
            image[sr][sc] = newColor_t;
            if (sr + 1 < m) {
                bfs(image, sr + 1, sc);
            }
            if (sr - 1 >= 0) {
                bfs(image, sr - 1, sc);
            }
            if (sc + 1 < n) {
                bfs(image, sr, sc + 1);
            }
            if (sc - 1 >= 0) {
                bfs(image, sr, sc - 1);
            }
            return true;
        }
        return false;
    }
};