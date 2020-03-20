/*
* @Author: Adrián Epifanio
* @Date:   2020-03-20 13:07:04
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 14:34:41
*/

#include "../include/calendar.hpp"

/**
 * @brief      Constructs a new instance.
 */
Calendar::Calendar () {
	std::cout << std::endl << "Error, the calendar must receive at least the number of teams" << std::endl;
	exit(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  teamsNumber  The teams number
 */
Calendar::Calendar (int teamsNumber) {
	teamsNumber_ = teamsNumber;
	for (int i = 1; i <= teamsNumber; i++) {
		std::string name = "Team";
		name += std::to_string(i);
		teams_.push_back(name);
	}
	teams_.resize(teamsNumber_);
	for (int i = 0; i < teamsNumber - 1; i++)
		teams_[i].resize(teamsNumber_ - 1);
	std::cout <<"TErmin";
	generateCalendarPow2(0, 7);
	//generateCalendarPow2(1, teamsNumber_ - 1);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  teamsNumber  The teams number
 * @param[in]  teams        The teams
 */
Calendar::Calendar (int teamsNumber, std::vector<std::string> teams) {
	teams_.resize(teamsNumber);
	teamsNumber_ = teamsNumber;
	for (int i = 0; i < teamsNumber; i++)
		teams_[i] = teams[i];
}

/**
 * @brief      Destroys the object.
 */
Calendar::~Calendar () {

}

/**
 * @brief      Gets the teams number.
 *
 * @return     The teams number.
 */
int Calendar::get_TeamsNumber (void) const {
	return teamsNumber_;
}

/**
 * @brief      Gets the teams.
 *
 * @return     The teams.
 */
std::vector<std::string> Calendar::get_Teams (void) const {
	return teams_;
}

/**
 * @brief      Gets the calendar.
 *
 * @return     The calendar.
 */
std::vector<std::vector<int>> Calendar::get_Calendar (void) const {
	return calendar_;
}

/**
 * @brief      Sets the teams number.
 *
 * @param[in]  teamsNumber  The teams number
 */
void Calendar::set_TeamsNumber (int teamsNumber) {
	teamsNumber_ = teamsNumber;
}

/**
 * @brief      Sets the teams.
 *
 * @param[in]  teams  The teams
 */
void Calendar::set_Teams (std::vector<std::string> teams) {
	teams_ = teams;
}

/**
 * @brief      Sets the calendar.
 *
 * @param[in]  calendar  The calendar
 */
void Calendar::set_Calendar (std::vector<std::vector<int>> calendar) {
	calendar_ = calendar;
}

void Calendar::generateCalendarPow2 (int i, int j) {
	std::cout << std::endl << "ASSSSSSSSS" << i << j << std::endl;
	if ((j - i) == 1) {	
		// Play between themselves the same day
		std::cout << std::endl << "CASO base" << std::endl;
		calendar_[i][1] = j;
		calendar_[j][1] = i;
		std::cout << std::endl << "TERMIN base" << std::endl;
	}
	else {
		int half = round((i + j) / 2);
		generateCalendarPow2(i, half);
		generateCalendarPow2(half + 1, i);
	}
}

void Calendar::generateCalendar (void) {

}


std::ostream& operator << (std::ostream& os, const Calendar& calendar) {

}

void Calendar::write(std::ostream& os) {
	for (int i = 0; i < teams_.size(); i++) {
		std::cout << teams_[i] << ": ";
		for (int j = 0; j < teams_.size() - 1; j++) {
			std::cout << calendar_[i][j];
		}
		std::cout << std::endl;

	}

}



  




	 