#include <models/PointModel.h>


namespace tiger{
namespace trains{
namespace models{

    PointModel::PointModel(const int idx, const int postId) :
        idx(idx), postId(postId){
    }

    const int PointModel::getIdx() const{
        return idx;
    }

    const int PointModel::getPostId() const{
        return postId;
    }

}
}
}
