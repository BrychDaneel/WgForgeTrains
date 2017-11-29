#include <models/LineModel.h>


namespace tiger{
namespace trains{
namespace models{

    LineModel::LineModel(){
    }

    LineModel::LineModel(const int idx, const int length, const int startPoint, const int endPoint) :
        idx(idx), length(length), startPoint(startPoint), endPoint(endPoint){
    }

    int LineModel::getIdx() const{
        return idx;
    }

    int LineModel::getLength() const{
        return length;
    }

    int LineModel::getStartPoint() const{
        return startPoint;
    }

    int LineModel::getEndPoint() const{
        return endPoint;
    }

    void LineModel::setIdx(const int idx){
        this->idx = idx;
    }

    void LineModel::setLength(const int lenght){
        this->length = lenght;
    }

    void LineModel::setStartPoint(const int startPoint){
        this->startPoint = startPoint;
    }

    void LineModel::setEndPoint(const int endPoint){
        this->endPoint = endPoint;
    }

}
}
}
