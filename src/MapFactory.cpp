#include <MapFactory.hpp>
#include <ConcreteBonusFactory.hpp>

MapFactory::MapFactory(){
	bonusFactory_ = unique_ptr<ConcreteBonusFactory>(new ConcreteBonusFactory());
}