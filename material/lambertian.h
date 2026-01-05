
#ifndef _LAMBERTIAN_H
#define _LAMBERTIAN_H

#include "material.h"

#include <memory>

class lambertian : public material {
	std::shared_ptr<texture> albedo;

public:
	lambertian(std::shared_ptr<texture> albedo) noexcept;

	bool scatter(const ray &r, const hit_record &hit, vec3 &attenuation, ray &scattered) const override;
};

#endif /* _LAMBERTIAN_H */
