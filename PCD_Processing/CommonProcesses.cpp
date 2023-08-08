//
// Created by kaykac on 29.11.2022.
//



#include "CommonProcesses.h"


/*!
 * This constructor keeps the file location in a string with @param fname and gives information about whether it can be opened or not.
 */
CommonProcesses::CommonProcesses(string fname):file_path(fname){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud) == -1)
    {
        PCL_ERROR ("File could not be read!\n");
        exit(1);
    }
}

/*!
 * This overloaded constructor is used to generate and save random pcd. It is not so necessary.
 * @param tname --> name of PCD
 * @param w --> width of PCD
 * @param h --> height of PCD
 */
CommonProcesses::CommonProcesses(string tname,int w, int h): file_path(tname),width(w),height(h){
    pcl::PointCloud<pcl::PointXYZ> cloud;

    cloud.width    = width;
    cloud.height   = height;
    cloud.is_dense = false;
    cloud.points.resize (cloud.width * cloud.height);

    for (auto& point: cloud)
    {
        point.x = /*1024 * */rand () / (RAND_MAX + 1.0f);
        point.y = /*1024 * */rand () / (RAND_MAX + 1.0f);
        point.z = 1024 * rand () / (RAND_MAX + 1.0f);
    }

    pcl::io::savePCDFileASCII (tname, cloud);
    //std::cerr << "Saved " << cloud.size () << " data points to "<<tname<< std::endl;

    for (const auto& point: cloud)
        std::cerr << "    " << point.x << " " << point.y << " " << point.z << std::endl;

}

/*!
 * This destructor function is run to destroy the object.
 */
CommonProcesses::~CommonProcesses() {
}



/*!
 * @param a This function makes the sampling of pcd according to this parameter.
 */
void CommonProcesses::samplePCD(double a){


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud);


    double sampling_rate = a;


    pcl::PointCloud<pcl::PointXYZ>::Ptr sampled_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
    pcl::RandomSample<pcl::PointXYZ> random_sampler;
    random_sampler.setInputCloud (cloud);
    random_sampler.setSample (cloud->size () * sampling_rate);
    random_sampler.filter (*sampled_cloud);

    // Saving sampled PCD (to the new file or over the original file)
    //pcl::io::savePCDFileASCII ("sampled.pcd", *sampled_cloud);
    pcl::io::savePCDFileASCII (file_path, *sampled_cloud);



}


/*!
 * @param a This function makes the rotating of pcd according to this parameter.
 */
void CommonProcesses::rotatePCD (double a){

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud);

    Eigen::Matrix4f transform_matrix = Eigen::Matrix4f::Identity();
    float theta = (a * 2 * M_PI)/360;
    transform_matrix (0,0) = cos (theta);
    transform_matrix (0,1) = -sin(theta);
    transform_matrix (1,0) = sin (theta);
    transform_matrix (1,1) = cos (theta);

    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
    pcl::transformPointCloud (*cloud, *transformed_cloud, transform_matrix);

    //pcl::io::savePCDFileASCII ("rotated.pcd", *transformed_cloud);
    pcl::io::savePCDFileASCII (file_path, *transformed_cloud);

}

/*!
 * @param a This function makes the scaling of pcd according to this parameter.
 */
void CommonProcesses::scalePCD(double a){

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ> (file_path, *cloud);

    pcl::PointXYZ min_point, max_point;
    pcl::getMinMax3D (*cloud, min_point, max_point);

  
    double scale = a;
    for (size_t i = 0; i < cloud->points.size (); ++i)
    {
        cloud->points[i].x = (cloud->points[i].x - min_point.x) * scale + min_point.x;
        cloud->points[i].y = (cloud->points[i].y - min_point.y) * scale + min_point.y;
        cloud->points[i].z = (cloud->points[i].z - min_point.z) * scale + min_point.z;
    }

    //pcl::io::savePCDFileASCII ("scaled.pcd", *cloud);
    pcl::io::savePCDFileASCII (file_path, *cloud);
}

/*!
 * This function allows the pcd to be displayed on an extra screen.
 */
void CommonProcesses::viewPCD (){

    PointCloud<PointXYZ>::Ptr cloud (new PointCloud<PointXYZ>);
    io::loadPCDFile<PointXYZ> (file_path, *cloud);
    pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
    viewer.showCloud (cloud);
    while (!viewer.wasStopped ()){
    }
}

/*!
 * This function allows pcd to read values in terminal.
 */
void CommonProcesses::readPCD() {
    PointCloud<PointXYZ>::Ptr cloud (new PointCloud<PointXYZ>);
    io::loadPCDFile<PointXYZ> (file_path, *cloud);

    std::cout << "Loaded "
              << cloud->width * cloud->height
              << " data points from "<<file_path<<" with the following fields: "
              << std::endl;

    for (const auto& point: *cloud)
        std::cout << "    " << point.x
                  << " "    << point.y
                  << " "    << point.z << std::endl;

}
