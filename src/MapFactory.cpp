#include <Prototype/MapFactory.hpp>
#include <Prototype/ConcreteBonusFactory.hpp>

MapFactory::MapFactory(){
	bonusFactory_ = unique_ptr<ConcreteBonusFactory>(new ConcreteBonusFactory());
}