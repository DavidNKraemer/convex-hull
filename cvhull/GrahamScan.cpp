#include "GrahamScan.h"
#include <algorithm>

namespace ams562 {

  bool is_left(Point2D orig, Point2D p1, Point2D p2) {
    return orig.orientation(p1, p2) < 0;
  }

  bool is_collinear(Point2D orig, Point2D p1, Point2D p2) {
    return orig.orientation(p1, p2) == 0;
  }

  bool is_right(Point2D orig, Point2D p1, Point2D p2) {
    return orig.orientation(p1, p2) > 0;
  }

  bool is_lower(Point2D p1, Point2D p2) {
    if (p1.y() == p2.y()) 
      return p1.x() < p2.x();
    else 
      return p1.y() < p2.y();
  }



  void GrahamScan::apply(std::vector<Point2D> &pc, std::vector<Point2D> &ch) const {

    //
    // First find the lowest point by using std::max_element
    // if there are ties, pick the most left one
    auto sw_iterator = std::min_element(
        pc.begin(), 
        pc.end(),

        // comparison function returns true if p1 is lower than p2
        is_lower);

    //
    // Then, swap that point with the first element in pc
    std::iter_swap(pc.begin(), sw_iterator);

    //
    // Next step is to sort the 2nd point to the last point in pc
    // by polar angle with the first point in pc
    // Note that the first point in pc is the lowest point in the
    // point cloud. std::sort
    std::sort(pc.begin() + 1, 
        pc.end(), 
        [&pc](Point2D p1, Point2D p2) {
        return pc[0].orientation(p1, p2) < 0; 
        }
        );

    //
    // Push back the first and second points to the back
    // of ch, push_back of ch should be used
    ch.push_back(*pc.begin());
    ch.push_back(*(pc.begin() + 1));

    //
    // Bonus, I do the cur for you

    auto cur = pc.begin() + 2;
    while (cur != pc.end()) {
      //
      // Get the last 2 points in ch by using iterators
      // note that you can start with ch.end(), be aware
      // of the position of ch.end()

      auto ch_ult = ch.end() - 1; // ultimate
      auto ch_pen = ch.end() - 2; // penultimate

      //
      // Compute the orientation information of ch's last1
      // last2 and cur

      //
      // if cur is to left of last1_last2
      // then push cur to ch
      if (is_left(*cur, *ch_pen, *ch_ult)) {
        ch.push_back(*cur);
        cur ++;
      }

      //
      // else if cur is collinear and cur lies futher
      // replace the last point of ch by cur
      else if (is_collinear(*cur, *ch_pen, *ch_ult)) {
        *ch_ult = *cur;
        cur ++;
      }

      //
      // else, pop the last point back from ch
      // and keep ch unchanged
      else {
        ch.pop_back();
      }
    }
  }

}
