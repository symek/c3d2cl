#include <iostream>
#include "ezc3d.h"
#include "CL/CL_Clip.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ezc3d::c3d c3d("external/ezc3d/example/markers_analogs.c3d");

    // Add two new points to the c3d (one filled with zeros, the other one with data)
    c3d.point("new_point1"); // Add empty
    std::vector<ezc3d::DataNS::Frame> frames_point;
    ezc3d::DataNS::Points3dNS::Points pts_new;
    ezc3d::DataNS::Points3dNS::Point pt_new;
    pt_new.x(1.0);
    pt_new.y(2.0);
    pt_new.z(3.0);
    pts_new.point(pt_new);
    for (size_t i=0; i<c3d.data().nbFrames(); ++i){
        ezc3d::DataNS::Frame frame;
        frame.add(pts_new);
        frames_point.push_back(frame);
    }
    c3d.point("new_point2", frames_point); // Add the previously created
    return 0;
}