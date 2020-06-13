#ifndef ABHIJEET_THROTTLE_1A
#define ABHIJEET_THROTTLE_1A

namespace abhijeet1A
{
	class throttle
	{
	public:
		/* Constructor */
		throttle(int size);
		throttle();
		throttle(int size, int current_pos);
		/* All member functions */
		void shutoff();
		void set_throttle_position(int amount);
		bool throttle_on() const;
		/* In-line definitions for member functions*/
		double flow() const { return position / double(top_position); }
		bool flow_more_than_half() const;

	private:
		int position;
		int top_position;


	protected:
	};

	bool operator ==(const throttle& A, const throttle& B);
	bool operator !=(const throttle& A, const throttle& B);

}

#endif
