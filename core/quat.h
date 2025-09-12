#ifndef _QUAT_H
#define _QUAT_H

#include <cmath>
#include <istream>
#include <ostream>
#include <tuple>

class quat {
	float e[4];

public:
	constexpr quat() :
			quat(0.0f, 0.0f, 0.0f, 1.0f) {}
	constexpr quat(float x, float y, float z, float w) :
			e{ x, y, z, w } {}

	constexpr quat(const vec3 &axis, float angle) {
		vec3 ax = axis.normalized() * sin(angle * 0.5f);
		e[0] = ax[0];
		e[1] = ax[1];
		e[2] = ax[2];
		e[3] = cos(angle * 0.5f);
	}

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float w() const { return e[3]; }
	inline float &x() { return e[0]; }
	inline float &y() { return e[1]; }
	inline float &z() { return e[2]; }
	inline float &w() { return e[3]; }

	inline vec3 xyz() const { return vec3(e[0], e[1], e[2]); }

	const quat &operator=(const quat &v) {
		if (this == &v) return *this;
		for (int i = 0; i < 4; i++) {
			e[i] = v.e[i];
		}
		return *this;
	}

	quat mul(const quat &q) {
		return quat(w() * q.x() + x() * q.w() + y() * q.z() - z() * q.y(),
				w() * q.y() - x() * q.z() + y() * q.w() + z() * q.x(),
				w() * q.z() + x() * q.y() - y() * q.x() + z() * q.w(),
				w() * q.w() - x() * q.x() - y() * q.y() - z() * q.z());
	}

	quat operator*(const quat &v) {
		return quat(x() * v.x(), y() * v.y(), z() * v.z(), w() * v.w());
	}

	quat inverse() const {
		return quat(-x(), -y(), -z(), w());
	}

	inline float length() const {
		return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3]);
	}

	inline quat normalized() const {
		const float len = length();
		return quat(e[0] / len, e[1] / len, e[2] / len, e[3] / len);
	}
};

inline vec3 rotate(const vec3 &v, const quat &q) {
	auto t = 2 * cross(q.xyz(), v);
	return v + q.w() * t + cross(q.xyz(), t);
}

inline quat normalize(const quat &q) {
	return q.normalized();
}

inline std::istream &operator>>(std::istream &in, quat &q) {
	return in >> q.x() >> q.y() >> q.z() >> q.w();
}

inline std::ostream &operator<<(std::ostream &out, quat &q) {
	return out << q.x() << ' ' << q.y() << ' ' << q.z() << ' ' << q.w();
}

#endif
