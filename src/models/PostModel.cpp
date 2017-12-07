#include <models/PostModel.h>


namespace tiger{
namespace trains{
namespace models{


PostModel::PostModel(){
}


PostModel::PostModel(const int idx, const PostType type, const int armor, const string name,
                     const int population, const int product, const int replenishment, const int productCapacity,
                     const int armorCapacity, const int nextLevelPrice, const int populationCapacity, const int level):
    idx(idx), type(type), armor(armor), name(name), population(population), product(product),
    replenishment(replenishment), productCapacity(productCapacity),
    armorCapacity(armorCapacity), nextLevelPrice(nextLevelPrice), populationCapacity(populationCapacity), level(level)
{
}


int PostModel::getIdx() const{
    return idx;
}


PostType PostModel::getType() const{
    return type;
}


int PostModel::getArmor() const{
    return armor;
}


const string& PostModel::getName() const{
    return name;
}


int PostModel::getPopulation() const{
    return population;
}


int PostModel::getProduct() const{
    return product;
}


int PostModel::getReplenishment() const{
    return replenishment;
}


int PostModel::getProductCapacity() const{
    return productCapacity;
}


int PostModel::getArmorCapacity() const{
    return armorCapacity;
}


int PostModel::getNextLevelPrice() const{
    return nextLevelPrice;
}


int PostModel::getPopulationCapacity() const{
    return populationCapacity;
}


int PostModel::getLevel() const{
    return level;
}


void PostModel::setIdx(const int idx){
    this->idx = idx;
}


void PostModel::setType(const PostType type){
    this->type = type;
}


void PostModel::setArmor(const int armor){
    this->armor = armor;
}


void PostModel::setName(const string name){
    this->name = name;
}


void PostModel::setPopulation(const int population){
    this->population = population;
}


void PostModel::setProduct(const int product){
    this->product = product;
}


void PostModel::setReplenishment(const int replenishment){
    this->replenishment = replenishment;
}


void PostModel::setProductCapacity(const int productCapacity){
    this->productCapacity = productCapacity;
}


void PostModel::setArmorCapacity(const int armorCapacity){
    this->armorCapacity = armorCapacity;
}


void PostModel::setNextLevelPrice(const int nextLevelPrice){
    this->nextLevelPrice = nextLevelPrice;
}


void PostModel::setPopulationCapacity(const int populationCapacity){
    this->populationCapacity = populationCapacity;
}


void PostModel::setLevel(const int level){
    this->level = level;
}


void PostModel::addEvent(const EventModel& event){
    eventList.push_back(event);
}


void PostModel::clearEventList(){
    eventList.clear();
}


const std::vector<EventModel>& PostModel::getEventList() const{
    return eventList;
}


}
}
}
