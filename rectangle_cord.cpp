#include <iostream>
using namespace std;

class rectangle_cord
{
private:
    int height;
    int width;
    pair <int, int> bottomLeft;
public:
    void Point() {
        cout << bottomLeft.first << ", " << bottomLeft.second << endl;
    }
    int add_point(int x, int y) {
        bottomLeft.first = x;
        bottomLeft.second = y;
        return 0;
    }
    int add_height(int h) {
        height = h;
        return 0;
    }
    int add_width(int w) {
        width = w;
        return 0;
    }
    void getAllCorners() {
        cout << "1) " << bottomLeft.first << ", " << bottomLeft.second << endl;
        cout << "2) " << bottomLeft.first << ", " << bottomLeft.second + height << endl;
        cout << "3) " << bottomLeft.first + width << ", " << bottomLeft.second + height << endl;
        cout << "4) " << bottomLeft.first + width << ", " << bottomLeft.second << endl;
    }
    bool intersects(rectangle_cord R) {
    bool proverka =
        this->bottomLeft.first + this->width <= R.bottomLeft.first ||
        R.bottomLeft.first + R.width <= this->bottomLeft.first ||
        this->bottomLeft.second + this->height <= R.bottomLeft.second ||
        R.bottomLeft.second + R.height <= this->bottomLeft.second;
        return !proverka;
    }
    int contains(int x, int y) {
        if (((this->bottomLeft.first < x) && (x < this->bottomLeft.first + this->width)) and ((this->bottomLeft.second < y) && (y < this->bottomLeft.second + this->height))) return 1;
        else return 0;
    }
     rectangle_cord& moveTo(int x, int y) {
        bottomLeft.first = x;
        bottomLeft.second = y;
        return *this;
    }

    rectangle_cord& resize(int w, int h) {
        width = w;
        height = h;
        return *this;
    }
};


int main() {
    rectangle_cord r;
    rectangle_cord R;
    pair <int, int> tochka;
    tochka.first = 6;
    tochka.second = 6;
    r.add_point(5,4);
    r.add_height(6);
    r.add_width(2);
    r.getAllCorners();
    R.add_point(1,1);
    R.add_height(3);
    R.add_width(5);
    if (r.intersects(R) == 1) cout << "est' peresechenye" << endl;
    else cout << "net peresechenye" << endl;
    if (r.contains(tochka.first, tochka.second) == 1) cout << "tochka vhodit v pryamougol'nik" << endl;
    else cout << "net peresechenye" << endl;
    r.moveTo(3, 15).resize(7, 5).getAllCorners();
    return 0;
}