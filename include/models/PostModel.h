#pragma once
#ifndef _TIGER_TRAINS_MODELS_POST_MODEL_H_
#define _TIGER_TRAINS_MODELS_POST_MODEL_H_


#include <models/PostType.h>

#include <string>


using std::string;


namespace tiger{
namespace trains{
namespace models{

    class PostModel{
        private:
            const int idx;
            const PostType type;
            const int armor;
            const string name;
            const int population;
            const int product;
        public:
            PostModel(const int idx, const PostType type, const int armor, const string name,
                const int population, const int product);

            const int getIdx() const;
            const PostType getType() const;
            const int getArmor() const;
            const string getName() const;
            const int getPopulation() const;
            const int getProduct() const;
    };
}
}
}



#endif
