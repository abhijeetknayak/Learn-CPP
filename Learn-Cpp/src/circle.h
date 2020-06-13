#ifndef ABHIJEET_CIRCLE_1A
#define ABHIJEET_CIRCLE_1A

namespace abhijeet1A
{
	class circle_location
	{
	public:
		/* Constructors */
		circle_location();
		circle_location(float initial_angle);

		/* Member functions */
		void move_position(float amount);
		float get_position() const;

	private:
		float angle;
	};
}

#endif
