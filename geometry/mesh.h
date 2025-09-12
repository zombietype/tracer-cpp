
#ifndef _MESH_H
#define _MESH_H

#include "core/bvh.h"
#include "core/hitable.h"
#include "shape.h"
#include <memory>

class triangle : public hitable {
	vec3 vert0;
	vec3 vert1;
	vec3 vert2;
	aabb box;

	vec3 get_normal(float u, float v) const;

public:
	triangle(vec3 p0, vec3 p1, vec3 p2);

	bool hit(const ray &r, float t_min, float t_max, hit_record &rec) const override;

	const aabb &get_aabb() const override;
};

class mesh : public shape {

	std::vector<std::shared_ptr<hitable> > polys;
	bvh blas;
	aabb box;

public:
	mesh(const std::vector<vec3> &vertices, const std::vector<int> &index, std::shared_ptr<material> mat);

	mesh(const std::vector<vec3> &vertices, std::shared_ptr<material> mat);

	bool hit(const ray &r, float t_min, float t_max, hit_record &rec) const override;

	const aabb &get_aabb() const override;
};

#endif // _MESH_H
