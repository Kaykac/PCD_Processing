//
// Created by kaykac on 29.11.2022.
//

#ifndef PCL_V1_REGIONGROWING_H
#define PCL_V1_REGIONGROWING_H
#include "Segmentation.h"






class RegionGrowing : Segmentation{
public:
    explicit RegionGrowing(const string &fname);
    void colorizedPCD();
    void individual_savePCD();

};


#endif //PCL_V1_REGIONGROWING_H
