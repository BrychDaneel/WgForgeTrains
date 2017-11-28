#include <models/LineModel.h>


namespace tiger{
namespace trains{
namespace models{

    LineModel::LineModel(){
    }

    LineModel::LineModel(const int idx, const int length, const int startPoint, const int endPoint) :
        idx(idx), length(length), startPoint(startPoint), endPoint(endPoint){
    }

    const int LineModel::getIdx() const{
        return idx;
    }

    const int LineModel::getLength() const{
        return length;
    }

    const int LineModel::getStartPoint() const{
        return startPoint;
    }

    const int LineModel::getEndPoint() const{
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
