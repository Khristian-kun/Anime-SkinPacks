#pragma once

#include "minecraftpe/entity/EntityDamageByEntitySource.h"

class EntityDamageByChildEntitySource : public EntityDamageByEntitySource
{
public:
	Entity *childEntity;	// 12

	EntityDamageByChildEntitySource(Entity &, Entity &, EntityDamageCause);
	virtual ~EntityDamageByChildEntitySource();
	virtual bool isChildEntitySource() const;
	virtual Entity *getChildEntity() const;
	virtual string getDeathMessage(string, Entity *) const;
};
