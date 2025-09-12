#ifndef _AABB_H
#define _AABB_H

#include "ray.h"
#include "transform.h"
#include <cmath>
#include <iostream>
#include <numeric>

class aabb {
	vec3 center;
	vec3 extent;

public:
	aabb() :
			center(0),
			extent(0) {}

	aabb(const vec3 &minp, const vec3 &maxp) :
			center(0.5f * (minp + maxp)),
			extent(0.5f * abs(maxp - minp)) {}

	bool hit(const ray &r, float t_min, float t_max) const;

	const vec3 get_min() const {
		return center - extent;
	}

	const vec3 get_max() const {
		return center + extent;
	}

	void get_corners(vec3 *corners) const {
		float x = extent.x();
		float y = extent.y();
		float z = extent.z();

		corners[0] = center + vec3(x, y, z);
		corners[1] = center + vec3(-x, y, z);
		corners[2] = center + vec3(x, -y, z);
		corners[3] = center + vec3(x, y, -z);
		corners[4] = center + vec3(x, -y, -z);
		corners[5] = center + vec3(-x, y, -z);
		corners[6] = center + vec3(-x, -y, z);
		corners[7] = center + vec3(-x, -y, -z);
	}

	static aabb combine(const aabb &a, const aabb &b) {
		return aabb(min(a.get_min(), b.get_min()), max(a.get_max(), b.get_max()));
	}

	static aabb transform(const aabb &a, const transform &t) {
		vec3 corners[8];
		a.get_corners(corners);
		for (int i = 0; i < 8; i++) {
			corners[i] = t.apply(corners[i]);
		}

		vec3 lo = corners[0];
		vec3 hi = corners[0];
		for (int i = 1; i < 8; i++) {
			lo = min(lo, corners[i]);
			hi = max(hi, corners[i]);
		}

		return aabb(lo, hi);
	}
};

#endif /* _AABB_H */
