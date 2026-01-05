#include "diffuse_light.h"

diffuse_light::diffuse_light(const color &emits) noexcept : emissive(emits) {
}

vec3 diffuse_light::emission(float u, float v, const vec3 &p) const {
	return emissive;
}
