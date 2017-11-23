#pragma once
#ifndef _TIGER_TRAINS_MODELS_PLAYER_MODEL_H_
#define _TIGER_TRAINS_MODELS_PLAYER_MODEL_H_


#include <string>


using std::string;


namespace tiger{
namespace trains{
namespace models{

    class PlayerModel{
        private:
            const int idx;
            const int home;
            const string name;
        public:
            PlayerModel(const int idx, const int home, const string name);
            const int getIdx() const;
            const int getHome() const;
            const string getName() const;
    };
}
}
}



#endif
