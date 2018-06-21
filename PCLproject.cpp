#include<iostream>
 
#include"gui.h"

int main(int argc, char *argv[]){

    gui app;
    app.gui_init();
    std::vector<cv::Point3f> objectPoints={cv::Point3f(1,0,5),cv::Point3f(2,2,5),cv::Point3f(3,0,10),cv::Point3f(4,-2,10),cv::Point3f(5,0,10),
                                            cv::Point3f(1,0,2.5),cv::Point3f(2,2,2.5),cv::Point3f(3,0,5),cv::Point3f(4,-2,5),cv::Point3f(5,0,5)};

    cv::Mat intrinsic=(cv::Mat1d(3, 3) << 300, 0, 320, 0, 300, 240, 0, 0, 1);

    Eigen::Vector3f position=Eigen::Vector3f(1,0,0);
    Eigen::Quaternionf orientation=Eigen::Quaternionf{Eigen::AngleAxisf{angle, Eigen::Vector3f{0, 0, 0}}};
    auto eigenRotMatrix=orientation.normalized().toRotationMatrix();
    cv::Mat opencvRotMatrix=(cv::Mat_<double>(3,3) <<
                                eigenRotMatrix(0,0),eigenRotMatrix(0,1),eigenRotMatrix(0,2),
                                eigenRotMatrix(1,0),eigenRotMatrix(1,1),eigenRotMatrix(1,2),
                                eigenRotMatrix(2,0),eigenRotMatrix(2,1),eigenRotMatrix(2,2));
    cv::Mat rotationVector;
    cv::Rodrigues(opencvRotMatrix,rotationVector);
    cv::Mat translationVector=(cv::Mat_<double>(1, 3) << position(0), position(1),position(2));
    std::vector<cv::Point2f> featureProjections;
    cv::projectPoints(objectPoints,rotationVector,translationVector,intrinsic,cv::noArray(),featureProjections,cv::noArray(),0);


    Eigen::Matrix4f pose1=Eigen::Matrix4f::Identity();



   return 0;
}