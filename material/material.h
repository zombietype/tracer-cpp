
#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "core/prelude.h"
#include "textures/prelude.h"

class material {
public:
	virtual bool scatter(const ray &r, const hit_record &hit, vec3 &attenuation, ray &scattered) const;

	virtual vec3 emission(float u, float v, const vec3 &p) const;
	virtual ~material() = default;
};

#endif /* _MATERIAL_H */
