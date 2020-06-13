#ifndef ABHIJEET_POINT_1A
#define ABHIJEET_POINT_1A

#include <iostream>

namespace abhijeet1A
{
	class point
	{
	public:
		/* Friend Functions */
		friend std::istream& operator >>(std::istream& in, point& A);

		/* Constructor */
		point(float x_initial = 0.0f, float y_initial = 0.0f);
		void shift(float x_amt, float y_amt);
		void rotate90();
		float get_x() const;
		float get_y() const;

	private:
		float x;
		float y;
	};

	int num_rotations_value(abhijeet1A::point P);
	int num_rotations_value_reference(abhijeet1A::point& P);
	std::istream& operator >>(std::istream& in, abhijeet1A::point& A);
	float distance(const abhijeet1A::point& A, const abhijeet1A::point& B);
	bool operator ==(const abhijeet1A::point& A, const abhijeet1A::point& B);
	bool operator !=(const abhijeet1A::point& A, const abhijeet1A::point& B);
	std::ostream& operator <<(std::ostream& out, const abhijeet1A::point& A);
}

#endif
