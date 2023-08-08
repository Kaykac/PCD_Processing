//
// Created by kaykac on 29.11.2022.
//


#ifndef PROJECT_V0_1_COMMONPROCESSES_H
#define PROJECT_V0_1_COMMONPROCESSES_H

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/common/common.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/random_sample.h>



using namespace std;
using namespace pcl;

class CommonProcesses {
public:
    CommonProcesses(string fname);
    CommonProcesses(string tname,int w, int h);
    ~CommonProcesses();
    void readPCD();
    void viewPCD();
    void scalePCD(double a);
    void rotatePCD (double a);
    void samplePCD(double a);

protected:


    //! string for PCS's path
    string file_path="";
    //! integer for creating random pcd width.
    int width;
    //! integer for creating random pcd height.
    int height;


};


#endif //PROJECT_V0_1_COMMONPROCESSES_H