#include "CommonProcesses.h"
#include "Segmentation.h"
#include "RANSAC.h"
#include "RegionGrowing.h"



int main() {
    //CommonProcesses c("depth_image0101_sampling.pcd");        //reading pcd in constructor
    //c.readPCD();                                              //reading pcd in terminal
    //c.viewPCD();                                              //viewing pcd in new window
    //c.rotatePCD(180);                                         //rotating pcd
    //c.viewPCD();                                              //view,ng again pcd

/*************************************************************************************************************************/
                                            //segmentation class can be use base class functions
    Segmentation s("depth_image0118_sampling.pcd");
    s.viewPCD();
    //s.rotatePCD(180);
    ///s.samplePCD(2);
    //s.scalePCD(0.5);
/*************************************************************************************************************************/
    //RANSAC r("depth_image0118_sampling.pcd");                 //reading pcd in constructor (with inheritance)
    //r.individual_savePCD();                                   //saving individual page on file
    //r.viewPCD();
    //r.colorizedPCD();                                         //colorizing pcd and viewing each parth
/************************************************************************************************************************/
    //RegionGrowing rg("depth_image0118_sampling.pcd");         //reading pcd in constructor (with inheritance)
    //rg.colorizedPCD();                                        //for detecting correct member function call

    return 0;
}