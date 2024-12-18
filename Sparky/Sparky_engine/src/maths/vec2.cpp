#include"vec2.h"

namespace sparky {
	namespace maths {

		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}
		
		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;
		
			return *this;
		}	

		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::devide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		vec2& operator+(vec2& left, const vec2& right)
		{
			return left.add(right);
		}

		std::ostream& operator << (std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << "," << vector.y << ")";
			return stream;
		}

	}	}