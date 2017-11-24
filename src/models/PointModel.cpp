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

    const int PointModel::getPostId() const{
        return postId;
    }

    bool PointModel::hasPost() const{
        return postId != 0;
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
