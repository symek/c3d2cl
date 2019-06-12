#include "ezc3d.h"
#include "CL/CL_Clip.h"
#include <iostream>

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        std::cout << "> c3d2cl file.c3d [file.clip]" << "\n";
        return 1;
    }

    ezc3d::c3d c3d(argv[1]);
    const size_t num_frames  = c3d.header().nbFrames();
    const size_t num_points  = c3d.header().nb3dPoints();
    const size_t samples     = c3d.header().frameRate();
    const size_t start_frame = c3d.header().firstFrame();
    const size_t end_frame   = c3d.header().lastFrame();

    CL_Clip clip(num_frames);
    clip.setTrackCapacity(num_points);
    clip.setSampleRate(samples);
    clip.setStart(start_frame);
    clip.setTrackLength((int)(end_frame-start_frame+1));

    const auto point_labels = c3d.parameters().group("POINT").parameter("LABELS").valuesAsString();

    for (size_t channel=0, label=0; channel<num_points; ++channel, ++label) {
        const auto point = c3d.data().frame(start_frame).points().point(channel);

        if (point.isempty()) {
            std::cout << "Skipping empty point..." << point_labels[label] << "\n" ;
            continue;
        }

        std::string channel_name{point_labels[label]};
        CL_Track *trackx = clip.addTrack("point_tx" +  std::to_string(channel));
        CL_Track *tracky = clip.addTrack("point_ty" +  std::to_string(channel));
        CL_Track *trackz = clip.addTrack("point_tz" +  std::to_string(channel));

        fpreal *datax = trackx->getData();
        fpreal *datay = tracky->getData();
        fpreal *dataz = trackz->getData();

        const auto frames = c3d.data().frames();

        size_t frame_index = start_frame;
        for(const auto & frame: frames) {
            datax[frame_index] = frame.points().point(channel).x();
            datay[frame_index] = frame.points().point(channel).y();
            dataz[frame_index] = frame.points().point(channel).z();
            frame_index++;
        }
    }

    if (argc > 2) {
        clip.save(argv[2]);
    }
    return 0;
}