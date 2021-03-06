#pragma once
#include <iostream>

namespace Math
{
	class vec4 {
	public:
		float x;
		float y;
		float z;
		float w;

		vec4() {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
		vec4(float const nx, float const ny, float const  nz, float const  nw) {
			x = nx;
			y = ny;
			z = nz;
			w = nw;
		}
		vec4(vec4 const& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}

		void operator=(vec4 const& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
		}
		vec4 operator-() {
			vec4 newVec(-x, -y, -z, -w);
			return newVec;
		}
		vec4 operator+(vec4 const& v) {
			vec4 newVec(x + v.x, y + v.y, z + v.z, w + v.w);
			return newVec;
		}
		void operator+=(vec4 const& v) {
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
			this->w += v.w;
		}
		vec4 operator-(vec4 const& v) {
			vec4 newVec(x - v.x, y - v.y, z - v.z, w - v.w);
			return newVec;
		}
		void operator-=(vec4 const& v) {
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
			this->w -= v.w;
		}
		void operator*=(float const v) {
			this->x *= v;
			this->y *= v;
			this->z *= v;
			this->w *= v;
		}
		vec4 operator*(float const scalar) {
			vec4 newVec(x * scalar, y * scalar, z * scalar, w * scalar);
			return newVec;
		}
		bool operator==(vec4 const& rhs) {
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		bool operator!=(vec4 const& v) {
			if ((x != v.x) || (y != v.y) || (z != v.z) || (w != v.w))
				return true;
			else
				return false;
		}
		float& operator[](unsigned int const i) {
			float returnValue;
			if (i > 3) {
				std::cerr << "Error\n";
				returnValue = -1;
			}
			else {
				if (i == 0) {
					return x;
				}
				else if (i == 1) {
					return y;
				}
				else if (i == 2) {
					return z;
				}
				else if (i == 3) {
					return w;
				}
			}
			return returnValue;
		}
		const float operator[](unsigned int const i) const {
			float returnValue = -1;
			if (i > 3) {
				std::cerr << "Error\n";
			}
			else {
				if (i == 0) {
					return x;
				}
				else if (i == 1) {
					return y;
				}
				else if (i == 2) {
					return z;
				}
				else if (i == 3) {
					return w;
				}
			}
			return returnValue;
		}


		float setElement(unsigned int const i, float const value) {
			if (i > 3) {
				std::cerr << "Error\n";
				return -1;
			}

			if (i == 0)
				x = value;
			else if (i == 1)
				y = value;
			else if (i == 2)
				z = value;
			else if (i == 3)
				w = value;
			return 0;
		}
		float getElement(unsigned int const i)const {
			if (i > 3) {
				std::cerr << "Error\n";
				return -1;
			}

			if (i == 0)
				return x;
			else if (i == 1)
				return y;
			else if (i == 2)
				return z;
			else if (i == 3)
				return w;
			return 0;
		}
		int printVec4()const {
			std::cout << x << ", " << y << ", " << z << ", " << w << "\n";
			return 0;
		}
	};

	float dot(vec4 const& a, vec4 const& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}
	float length(vec4 const& v) {
		return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	}
	vec4 normalize(vec4 const& v) { //convert to unit vector
		float vecLen = length(v);
		vec4 newVec;
		newVec.x = v.x / vecLen;
		newVec.y = v.y / vecLen;
		newVec.z = v.z / vecLen;
		newVec.w = v.w;
		return newVec;
	}
}
