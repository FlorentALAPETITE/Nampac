#include <Factory/MapFactory.hpp>
#include <Factory/ConcreteBonusFactory.hpp>

MapFactory::MapFactory(){
	bonusFactory_ = unique_ptr<ConcreteBonusFactory>(new ConcreteBonusFactory());
}