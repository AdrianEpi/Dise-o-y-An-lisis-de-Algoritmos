/*
* @Author: Adrián Epifanio
* @Date:   2020-03-20 13:07:04
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 16:07:06
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
	calendar_.resize(teamsNumber_);
	for (int i = 0; i < teamsNumber; i++)
		calendar_[i].resize(teamsNumber_ - 1);
	generateCalendarPow2(0, teamsNumber_ - 1);
	write(std::cout);
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
	if ((j - i) == 1) {	
		// Play between themselves the same day
		//std::cout << std::endl << "i: " << i << "   j: " << j << std::endl;
		calendar_[i][1] = j + 1;
		calendar_[j][1] = i + 1;
	}
	else {
		int half = round((i + j) / 2);
		generateCalendarPow2(i, half);
		generateCalendarPow2(half + 1, j);
		rotateSolution(i, half, (half - i + 1), (j - i), (half + 1));
		rotateSolution((half + 1), j, (half - i + 1), (j - i), i);
	}
}

void Calendar::rotateSolution (int team1, int team2, int day1, int day2, int starterTeam) {
	for (int i = day1; i <= day2; i++) {
		calendar_[team1][i] = starterTeam + i - day1 + 1;
	}
	for (int i = team1 + 1; i <= team2; i++) {
		calendar_[i][day1] = calendar_[i - 1][day2]; //el último contrincante de i-1 es ahora el primer contrincante de i
		for (int j = day1 + 1; j <= day2; j++) {
			calendar_[i][j] = calendar_[i - 1][j - 1]; //el contrincante de ayer de i-1, es el contrincante de hoy para i
		}
	}
}

void Calendar::generateCalendar (void) {

}


std::ostream& operator << (std::ostream& os, const Calendar& calendar) {

}

void Calendar::write(std::ostream& os) {
	std::cout << std::endl << std::endl;
	for (int i = 0; i < teamsNumber_ - 1; i++)
		std::cout <<"\tDay " << i + 1; 

	std::cout << std::endl << std::endl;
	for (int i = 0; i < teams_.size(); i++) {
		std::cout << teams_[i] << "\t";
		for (int j = 1; j < teams_.size(); j++) {
			std::cout << calendar_[i][j] << '\t';
		}
		std::cout << std::endl;

	}

}



  




	 