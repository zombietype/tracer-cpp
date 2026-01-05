
#include "lambertian.h"

lambertian::lambertian(std::shared_ptr<texture> albedo) noexcept
		: albedo(std::move(albedo)) {}

bool lambertian::scatter(const ray &r, const hit_record &hit, vec3 &attenuation, ray &scattered) const {
	vec3 target = hit.p + hit.normal + random_in_unit_sphere();
	scattered = ray(hit.p, target - hit.p);
	attenuation = albedo->sample(0, 0, hit.p);
	return true;
}
