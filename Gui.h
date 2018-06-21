#include <pcl/visualization/pcl_visualizer.h>

class Gui{
    public:
        gui();
        bool init_gui();
        bool draw_poses();
    private:

        boost::shared_ptr<pcl::visualization::PCLVisualizer> mViewer;


};

#include "Gui.inl"