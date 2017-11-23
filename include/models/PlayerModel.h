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
            int idx = 0;
            int home = 0;
            string name;
        public:
            PlayerModel();
            PlayerModel(const int idx, const int home, const string name);
            const int getIdx() const;
            const int getHome() const;
            const string getName() const;

            void setIdx(const int idx);
            void setHome(const int home);
            void setName(const string name);
    };
}
}
}



#endif
