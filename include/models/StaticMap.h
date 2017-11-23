#pragma once
#ifndef _TIGER_TRAINS_MODELS_STATIC_MAP_H_
#define _TIGER_TRAINS_MODELS_STATIC_MAP_H_


#include <models/PointModel.h>
#include <models/LineModel.h>

#include <string>
#include <vector>


using std::string;
using std::vector;


namespace tiger{
namespace trains{
namespace models{

    class StaticMap{
        private:
            int idx = 0;
            string name;
            vector<LineModel> lineList;
            vector<PointModel> pointList;
        public:
            StaticMap(const int idx, const string name);

            void addPoint(const PointModel& point);
            void addLine(const LineModel& line);

            const int getIdx() const;
            const string getName() const;
            const vector<LineModel> getLineList() const;
            const vector<PointModel> getPointList() const;

            void setIdx(const int idx) const;
            void setName(const string name) const;
            void clearLineList() const;
            void clearPointList() const;
    };
}
}
}



#endif
