#include "instance.h"
#include "core/hitable.h"

bool instance::hit(const ray &r, float t_min, float t_max, hit_record &rec) const {

	hit_record loc_rec;

	ray loc_ray = tx.ray_to_space(r);
	if (inner->hit(loc_ray, t_min, t_max, loc_rec)) {
		rec.normal = rotate(loc_rec.normal, tx.orientation);
		rec.p = tx.apply(loc_rec.p);
		rec.t = loc_rec.t * tx.scale;
		rec.mat = loc_rec.mat;
		rec.obj = loc_rec.obj;
		rec.u = loc_rec.u;
		rec.v = loc_rec.v;

		return true;
	}

	return false;
}

const aabb &instance::get_aabb() const {
	return box;
}
