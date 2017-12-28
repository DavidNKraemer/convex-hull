#include "ams562_cvhull.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace ams562;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "You must pass in the testing file\n";
    return EXIT_FAILURE;
  }
  std::string test_points_dir = "./tests/";
  std::string filename = argv[1];

  std::string results_dir = "./results/";

  CvHullBase *method = nullptr;

  // split method
  if (argc > 3) {
    // if you have other method, handle here
    // since currently we only have graham scan
    method = new GrahamScan();
  }
  else
    method = new GrahamScan();

  std::vector<Point2D> pc;
  std::vector<Point2D> ch;

  //
  // Estimate the size of pc and ch by using reserve!

  std::cout << "Fetching point cloud from [" 
    << test_points_dir + filename << "]" << std::endl;

  try {
    loadtxt(test_points_dir + filename, pc);
  } 

  catch (std::string err) {
    std::cerr << err << std::endl << "Aborting program." << std::endl;
    return 1;
  }

  compute_cvhull(pc, ch, *method);
  try {
    write2txt(results_dir + filename, ch);
  } 

  catch (std::string err) {
    std::cerr << err << std::endl << "Aborting program." << std::endl;
    return 1;
  }

  std::cout << "The result has been written to [" 
    << results_dir + filename << "]" << std::endl;

  if (method)
    delete method;
}
