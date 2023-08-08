//
// Created by kaykac on 29.11.2022.
//



#include "RANSAC.h"



/*!
 * This class inherited from class Segmentation works the same as the constructor function of most base class CommonProcesses.
 * @param fname --> file path.
 */
RANSAC::RANSAC(const string &fname) : Segmentation(fname) {
}



/*!
 * This function colors the pcd parts segmented according to RANSAC method and displays it in the viewer (with tolerated value 0.01).
 */
void RANSAC::colorizedPCD() {

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud);

    int segment_count = 0;
    while (cloud->points.size () > 0)
    {
    	// (!)I couldn't use this function because it didn't work properly and I had to repeat the code 
    	//segmented(0.01); 


        pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
        pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        seg.setOptimizeCoefficients (true);
        seg.setModelType (pcl::SACMODEL_PLANE); //! using SACMODEL_PLANE for surface segmentatipn
        seg.setMethodType (pcl::SAC_RANSAC); //! using RANSAC method
        seg.setDistanceThreshold (0.01); //! tolerated value is 0.01
        seg.setInputCloud (cloud);
        seg.segment (*inliers, *coefficients);





        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_colored (new pcl::PointCloud<pcl::PointXYZRGB>);
        pcl::copyPointCloud (*cloud, *cloud_colored);
        double randr = rand();  //! random value for R component
        double randg = rand();  //! random value for G component
        double randb = rand();  //! random value for B component
        for (size_t i = 0; i < inliers->indices.size (); ++i)
        {
            cloud_colored->points[inliers->indices[i]].r = randr;
            cloud_colored->points[inliers->indices[i]].g = randg;
            cloud_colored->points[inliers->indices[i]].b = randb;
        }

        pcl::visualization::CloudViewer viewer ("clored surface");
        viewer.showCloud (cloud_colored);
        while (!viewer.wasStopped ())
        {
        }




        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_segment (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::ExtractIndices<pcl::PointXYZ> extract;
        extract.setInputCloud (cloud);
        extract.setIndices (inliers);
        extract.filter (*cloud_segment);
        ++segment_count;

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
        extract.setNegative (true);
        extract.filter (*cloud_filtered);
        cloud = cloud_filtered;
    }


}

/*!
 * This function saves the segmented parts according to the RANSAC method one by one to the file. (with tolerated value 0.01).
 */
void RANSAC::individual_savePCD() {


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud);


    int segment_count = 0;
    while (cloud->points.size () > 0)
    {
    	
    	// (!)I couldn't use this function because it didn't work properly and I had to repeat the code 
    	//segmented(0.01); 

        pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
        pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        seg.setOptimizeCoefficients (true);
        seg.setModelType (pcl::SACMODEL_PLANE); //! using SACMODEL_PLANE for surface segmentatipn
        seg.setMethodType (pcl::SAC_RANSAC); //!using RANSAC method
        seg.setDistanceThreshold (0.01); //! tolerated value is 0.01
        seg.setInputCloud (cloud);
        seg.segment (*inliers, *coefficients);


        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_segment (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::ExtractIndices<pcl::PointXYZ> extract;
        extract.setInputCloud (cloud);
        extract.setIndices (inliers);
        extract.filter (*cloud_segment);
        std::stringstream ss;
        ss << "segment_" << segment_count << ".pcd"; //! name of saved parth.
        pcl::io::savePCDFile (ss.str (), *cloud_segment);
        ++segment_count;

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
        extract.setNegative (true);
        extract.filter (*cloud_filtered);
        cloud = cloud_filtered;
    }



}


/*!
 * This function segments pcd with RANSAC method.
 * @param a --> tolerated value
 */
void RANSAC::segmented(double a) {

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud);


    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    seg.setOptimizeCoefficients (true);
    seg.setModelType (pcl::SACMODEL_PLANE); //! using SACMODEL_PLANE for surface segmentatipn
    seg.setMethodType (pcl::SAC_RANSAC); //!using RANSAC method
    seg.setDistanceThreshold (a); //! tolerated value
    seg.setInputCloud (cloud);
    seg.segment (*inliers, *coefficients);


    if (inliers->indices.size () == 0)
    {
        PCL_ERROR ("Surface can not found!\n");
    }


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_segmented (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud (cloud);
    extract.setIndices (inliers);
    extract.setNegative (false);
    extract.filter (*cloud_segmented);
    std::cout << "surface segmented: " << cloud_segmented->points.size () << std::endl;



}
