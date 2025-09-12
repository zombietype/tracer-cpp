#ifndef _INSTANCE_H
#define _INSTANCE_H

#include "core/bvh.h"
#include "core/hitable.h"
#include "core/quat.h"
#include "core/transform.h"
#include "shape.h"
#include <memory>

class instance : public hitable {
	std::shared_ptr<hitable> inner;
	transform tx;
	aabb box;

public:
	instance(std::shared_ptr<hitable> obj, transform tx) :
			inner(std::move(obj)), tx(tx) {
		box = aabb::transform(inner->get_aabb(), tx);
	}

	bool hit(const ray &r, float t_min, float t_max, hit_record &rec) const override;

	const aabb &get_aabb() const override;
};

#endif
