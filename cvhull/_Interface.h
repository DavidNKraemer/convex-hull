#ifndef __INTERFACE_H
#define __INTERFACE_H

#include "_CvHullBase.h"
#include <fstream>
#include <iostream>
#include <exception>

namespace ams562 {
  inline void compute_cvhull(std::vector<Point2D> &pc, std::vector<Point2D> &ch,
      const CvHullBase &method) {
    method.apply(pc, ch);
  }

  void loadtxt(const std::string &filename, std::vector<Point2D> &p) {
    // check the size, if not zero, make it zero
    if (p.size())
      p.resize(0);

    std::ifstream infile(filename);
    if (infile.is_open()) {
      Point2D temp;
      while (infile >> temp)
        p.push_back(temp);
      infile.close();
    }
    else {

      std::string err = "[Error] Cannot open: " + filename + " to read!";
      throw err;
    }
  }

  void write2txt(const std::string &filename, const std::vector<Point2D> &p) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
      for (const auto & pt : p)
        outfile << pt << '\n';
      outfile.close();
    }
    else {
      std::string err = "[Error] Cannot open: " + filename + " to write!";
      throw err;
    }
  }
}

#endif
