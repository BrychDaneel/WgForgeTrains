#pragma once


namespace tiger{
namespace trains{
namespace models{


class LineModel{

private:

    int idx = 0;
    int length = 0;
    int startPoint = 0;
    int endPoint = 0;

public:

    LineModel();
    LineModel(const int idx, const int length, const int startPoint, const int endPoint);

    int getIdx() const;
    int getLength() const;
    int getStartPoint() const;
    int getEndPoint() const;

    void setIdx(const int idx);
    void setLength(const int lenght);
    void setStartPoint(const int startPoint);
    void setEndPoint(const int endPoint);

};


}
}
}
