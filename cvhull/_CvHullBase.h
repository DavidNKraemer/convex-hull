#ifndef __CVHULLBASE_H
#define __CVHULLBASE_H

#include "Point2D.h"
#include <vector>

namespace ams562 {
    class CvHullBase {
public:
        virtual void apply(
            std::vector<Point2D> &pc,
            std::vector<Point2D> &ch) const = 0;
            
        virtual ~CvHullBase() {}
    };
}

#endif
