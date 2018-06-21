#include <iostream>

#include <opencv2/core/eigen.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>

inline Gui::gui()
{
}

//---------------------------------------------------------------------------------------------------------------------

inline bool Gui::init_gui()
{
    mViewer  = boost::shared_ptr<pcl::visualization::PCLVisualizer>(new pcl::visualization::PCLVisualizer("3D Viewer"));
    mViewer->setBackgroundColor(100,100,100,0);
    mViewer->addCoordinateSystem(0.15,"base",0);
    mViewer->registerKeyboardCallback(&Visualizer::keycallback, *this, (void*)&mViewer);
    return true;
}

//---------------------------------------------------------------------------------------------------------------------

inline bool Gui::draw_poses(Eigen::Matrix4f _pose)
{



    mViewer.addCoordinateSystem(0.7, Eigen::Affine3f(cameras[i]->pose.inverse()),"camera_"+std::to_string(i));
    return true;
}