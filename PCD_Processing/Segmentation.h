//
// Created by kaykac on 29.11.2022.
//


#ifndef PCL_V1_SEGMENTATION_H
#define PCL_V1_SEGMENTATION_H

#include "CommonProcesses.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/segmentation/extract_clusters.h>
#include <random>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vector>
#include <string>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/filters/extract_indices.h>

class Segmentation : public CommonProcesses{
public:

    Segmentation(const string &fname);


    virtual void labeledPCD();
    virtual void colorizedPCD();
    virtual void individual_savePCD();
    virtual void segmented();

protected:







};


#endif //PCL_V1_SEGMENTATION_H
