#include "material.h"

bool material::scatter(const ray &r, const hit_record &hit, vec3 &attenuation, ray &scattered) const {
	return false;
};

vec3 material::emission(float u, float v, const vec3 &p) const {
	return vec3(0.0f);
}
