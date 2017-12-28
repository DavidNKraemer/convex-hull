#ifndef __POINT2D_H
#define __POINT2D_H

#include <iostream>

#define SWAP(T, lhs, rhs) do { \
  T temp = *(lhs); \
  *(lhs) = *(rhs); \
  *(rhs) = temp; \
} while (0);

namespace ams562 {

  class Point2D {
    public:
      //
      // Constructors
      Point2D() : x_(0), y_(0) { }

      Point2D(const Point2D &p) {
        x_ = p.x();
        y_ = p.y();
      }    

      Point2D(int x, int y) {
        x_ = x;
        y_ = y;
      }

      //
      // Methods for accessing
      // implementation needed
      int x() const { 
        return x_; 
      }

      int x() { 
        return x_; 
      }

      int y() const { 
        return y_; 
      }

      int y() { 
        return y_; 
      }

      //
      // orientation
      // implementation needed
      int orientation(const Point2D &a, const Point2D &b) const {
        return (b.x() - a.x()) * (y_ - a.y()) - (x_ - a.x()) * (b.y() - a.y());
      }

      //
      // backend swapping
      // implementation needed
      // void swap(Point2D &other) {
      //   SWAP(int, &x_, &(other.x_));
      //   SWAP(int, &y_, &(other.y_));
      // }

      //
      // Operator =
      // implementation needed
      Point2D & operator=(const Point2D &p) {
        x_ = p.x_;
        y_ = p.y_;

        return *this;
      }

    private:
      int x_, y_;
      friend std ::ostream & operator<<(std::ostream &, const Point2D &);
      friend std ::istream & operator>>(std::istream &, Point2D &);
  };

  //
  // ostream::operator<<
  inline std::ostream & operator<<(std::ostream &out, const Point2D &p) {
    out << p.x_ << ',' << p.y_;
    return out;
  }

  //
  // istream::operator>>
  // implementation needed
  inline std::istream & operator>>(std::istream &in, Point2D &p) {
    char dummy;
    in >> p.x_ >> dummy >>  p.y_;
    return in;
  }

  //
  // distance square
  // implementation needed
  inline int dist_sq(const Point2D &p1, const Point2D &p2) {
    int x_dst = (p2.x() - p1.x());
    int y_dst = (p2.y() - p1.y());
    return (x_dst * x_dst) + (y_dst * y_dst);
  }

}

#endif
