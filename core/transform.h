#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "core/quat.h"
#include "core/ray.h"
#include "core/vec3.h"

struct transform {
	quat orientation;
	vec3 translation;
	float scale;

	vec3 apply(const vec3 &v) const {
		return rotate(v * scale, orientation) + translation;
	}

	ray ray_to_space(const ray &r) const {
		vec3 o = r.origin();
		vec3 d = r.direction();

		o = rotate(o - translation, orientation.inverse()) / scale;
		d = rotate(d, orientation.inverse());

		return ray(o, d);
	}
};

#endif /* _TRANSFORM_H */
