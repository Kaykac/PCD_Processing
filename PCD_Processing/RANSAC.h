//
// Created by kaykac on 29.11.2022.
//


#ifndef PCL_V1_RANSAC_H
#define PCL_V1_RANSAC_H
#include "Segmentation.h"


class RANSAC : public Segmentation{
public:
    explicit RANSAC(const string &fname);
    void colorizedPCD();
    void individual_savePCD();
    void segmented(double a);


};


#endif //PCL_V1_RANSAC_H
