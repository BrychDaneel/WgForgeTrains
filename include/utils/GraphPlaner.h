#pragma once
#ifndef _TIGER_TRAINS_UTILS_GRAPH_PLANER_H_
#define _TCPSOCKET_H_


#include <vector>


using std::vector;
using std::pair;


namespace tiger{
namespace trains{
namespace utils{


class GraphPlaner{

private:

    struct Edge{

        int v;
        int t;
        float len;
        Edge(int v, int t, float len) : v(v), t(t), len(len){}

    };

    static bool isCollade(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    static float getTemperature(const vector<Edge>& edges, vector<pair<float, float> >& coords, float avgEdge);

public:

    static const vector<pair<float, float> > planeGraph(const vector<vector<pair<int, float> > >& graph, int seed=0);

};


}
}
}


#endif
