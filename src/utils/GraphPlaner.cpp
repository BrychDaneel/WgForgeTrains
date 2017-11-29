#include <utils/GraphPlaner.h>


#include <stdlib.h>
#include <cmath>


using std::tuple;


#define SQR(x) ((x)*(x))


namespace tiger{
namespace trains{
namespace utils{


bool GraphPlaner::isCollade(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
    float px = ( (x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4) ) / ( (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4) );
    //float py = ( (x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4) ) / ( (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4) );

    if (x1 > x2)
        std::swap(x1, x2);
    if (x3 > x4)
        std::swap(x3, x4);

    return (x1 < px && px < x2 && x3 < px && px < x4);
}


float GraphPlaner::getTemperature(const vector<Edge>& edges, vector<pair<float, float> >& coords, float avgEdge){
    float res = 0;
    for (const Edge e : edges){
        float sqrDist = SQR(coords[e.v].first - coords[e.t].first) + SQR(coords[e.v].second - coords[e.t].second);
        res += abs(sqrDist - e.len * e.len);
    }

    for (size_t i=0; i<coords.size(); i++)
        for (size_t ii=i+1; ii<coords.size(); ii++){
            float dist = hypot(coords[i].first - coords[ii].first, coords[i].second - coords[ii].second);
            if (dist < avgEdge * 0.7)
                res += SQR(avgEdge - dist);
        }


    for (const Edge e1 : edges)
        for (const Edge e2 : edges)
            if (isCollade(coords[e1.v].first, coords[e1.v].second, coords[e1.t].first, coords[e1.t].second,
                          coords[e2.v].first, coords[e2.v].second, coords[e2.t].first, coords[e2.t].second))
                res += avgEdge*avgEdge;

    return res;
}


const vector<pair<float, float> > GraphPlaner::planeGraph(const vector<vector<pair<int, float> > >& graph, int seed)
{
    srand(seed);

    size_t size = graph.size();

    float avgEdge = 0;
    vector<Edge> edges;
    for (size_t i=0; i<size; i++)
        for (size_t ii=0; ii<graph[i].size(); ii++){
            avgEdge += graph[i][ii].second;
            Edge e(i, graph[i][ii].first, graph[i][ii].second);
            edges.push_back(e);
        }

    avgEdge = abs(avgEdge / edges.size());

    float width = avgEdge * sqrt(size) * 2;
    float height = width;


    vector<pair<float, float> > coords;

    for (size_t i=0; i<size; i++)
        coords.push_back(pair<float, float>(rand()*1./RAND_MAX*width, rand()*1./RAND_MAX*height));

    int t = 80;
    float k = 0.973;
    int it = 300;
    float e = getTemperature(edges, coords, avgEdge);

    while (t > 0.0001){
        for (int i=0; i<it; i++){
            int v = rand() % size;
            float oldX = coords[v].first;
            float oldY = coords[v].second;
            coords[v] = pair<float, float>(rand()*1./RAND_MAX*width, rand()*1./RAND_MAX*height);

            float ne = getTemperature(edges, coords, avgEdge);
            float d = e - ne;

            if (ne < e)
                e = ne;
            else
                if (rand()*1./RAND_MAX < exp(d/t))
                    e = ne;
                else
                    coords[v] = pair<float, float>(oldX, oldY);
        }
        t *= k;
    }

    float minX = coords[0].first;
    float minY = coords[0].second;

    for (pair<int, float> c : coords){
        if (c.first < minX)
            minX = c.first;
        if (c.second < minY)
            minY = c.second;
    }

    for (size_t i=0; i<coords.size(); i++)
        coords[i] = pair<float, float>(coords[i].first - minX, coords[i].second - minY);

    return coords;

}


}
}
}
