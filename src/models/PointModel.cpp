#include <models/PointModel.h>


namespace tiger{
namespace trains{
namespace models{

    PointModel::PointModel(){
    }

    PointModel::PointModel(const int idx, const int postId) :
        idx(idx), postId(postId){
    }

    const int PointModel::getIdx() const{
        return idx;
    }

    void PointModel::setIdx(const int idx){
        this->idx = idx;
    }

    void PointModel::setPostId(const int postId){
        this->postId = postId;
    }
}
}
}
