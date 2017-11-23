#include <models/PostModel.h>


namespace tiger{
namespace trains{
namespace models{

    PostModel::PostModel(const int idx, const PostType type, const int armor, const string name,
                const int population, const int product):
        idx(idx), type(type), armor(armor), name(name), population(population), product(product)
    {
    }

    const int PostModel::getIdx() const{
        return idx;
    }

    const PostType PostModel::getType() const{
        return type;
    }

    const int PostModel::getArmor() const{
        return armor;
    }

    const string PostModel::getName() const{
        return name;
    }

    const int PostModel::getPopulation() const{
        return population;
    }

    const int PostModel::getProduct() const{
        return product;
    }

}
}
}
