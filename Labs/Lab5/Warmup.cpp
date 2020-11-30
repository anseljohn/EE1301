/**
 * WARMUP 1  
 */

class Point {
    public:
        void showPoint( );
        Point();

    Point(int newX, int newY) {
        xlocation = newX;
        ylocation = newY;
    }
    int xlocation;
    int ylocation; 
} ;


/**
 * a) Line 4
 * b) Yes it will work, but...
 * c) It's not smart, since they are prone to being used/overwritten incorrectly
 */

/**
 * ============== ============== ============== ============== ============== ==============
 */

/**
 * WARMUP 2
 */

int main() {
  Point.xlocation = 3;
  Point.ylocation = 10;
  Point p1;
  p1 = Point(5,6);
  Point p2( );
  return 0;
}

/**
 * a) It's trying to set the class' variable values instead of a constructed object's values
 * b) It constructs a point with xlocation = 5 and ylocation = 6
 * c) It's not constructing an object, it's declaring a function
 * d) A function p2() that returns a Point
 * e) Point p2;
 */

/**
 * ============== ============== ============== ============== ============== ==============
 */

/**
 * WARMUP 3
 */

void foo() {
  int *array = new int[100];
   for (int i = 0; i < 100; i++) {
        //do something
   }
}

