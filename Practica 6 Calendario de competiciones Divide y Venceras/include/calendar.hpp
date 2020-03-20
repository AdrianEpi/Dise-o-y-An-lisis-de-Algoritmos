#include <iostream>
#include <vector>
#include <string>
#include <cmath>


class Calendar {

	private:
		int teamsNumber_;
		std::vector<std::string> teams_;
		std::vector<std::vector<int>> calendar_;

	public:
		// Builders & Destroyer
		Calendar ();
		Calendar (int teamsNumber);
		Calendar (int teamsNumber, std::vector<std::string> teams);
		~Calendar ();

		// Getters & Setters
		int get_TeamsNumber (void) const;
		std::vector<std::string> get_Teams (void) const;
		std::vector<std::vector<int>> get_Calendar (void) const;

		void set_TeamsNumber (int teamsNumber);
		void set_Teams (std::vector<std::string> teams);
		void set_Calendar (std::vector<std::vector<int>> calendar);

		// Functions
		void generateCalendarPow2 (int i, int j);
		void generateCalendar (void);

		// Operators overload
		friend std::ostream& operator << (std::ostream& os, const Calendar& calendar);

		// Read & Write
		void write(std::ostream& os);

};