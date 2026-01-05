#ifndef _DIFFUSE_LIGHT_H
#define _DIFFUSE_LIGHT_H

#include "material.h"

class diffuse_light : public material {
	vec3 emissive;

public:
	diffuse_light(const color &emits) noexcept;

	vec3 emission(float u, float v, const vec3 &p) const override;
};

#endif /* _DIFFUSE_LIGHT_H */
