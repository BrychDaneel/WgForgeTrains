#pragma once


#include <string>


using std::string;


namespace tiger
{
namespace trains
{
namespace models
{


class PlayerModel
{
private:

    string idx;
    int home = 0;
    string name;

public:

    PlayerModel();
    PlayerModel(const string idx, const int home, const string name);
    const string getIdx() const;
    int getHome() const;
    const string getName() const;

    void setIdx(const string idx);
    void setHome(const int home);
    void setName(const string name);
};


}
}
}
