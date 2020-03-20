/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 6 Calendario de Competiciones DyV         =
    =            File name:     calendar.hpp                                       =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         20/03/2020                                         =
    =            Subject:       Diseño y Análisis de Algoritmos                    =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrián Epifanio
* @Date:   2020-03-20 13:07:04
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 17:14:15
*/

/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../include/calendar.hpp"

/*-------------------------------------------------*/

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
	initialize(teamsNumber);
	for (int i = 0; i < teamsNumber; i++) {
		std::string name = "Team";
		name += std::to_string(i + 1);
		teams_[i] = name;
	}
	algorythmSelector();
	write(std::cout);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  teamsNumber  The teams number
 * @param[in]  teams        The teams
 */
Calendar::Calendar (int teamsNumber, std::vector<std::string> teams) {
	initialize(teamsNumber);
	for (int i = 0; i < teamsNumber; i++)
		teams_[i] = teams[i];
	algorythmSelector();
	write(std::cout);
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


/**
 * @brief      Initializes the given teams number.
 *
 * @param[in]  teamsNumber  The teams number
 */
void Calendar::initialize (int teamsNumber) {
	set_TeamsNumber(teamsNumber);
	teams_.resize(teamsNumber);
	calendar_.resize(teamsNumber_);
	for (int i = 0; i < teamsNumber; i++)
		calendar_[i].resize(teamsNumber - 1);
}

/**
 * @brief      Determines if pow 2.
 *
 * @return     True if pow 2, False otherwise.
 */
bool Calendar::isPow2 (void) {
	int aux = 1;
	while (aux < get_TeamsNumber()) {
		aux *= 2;
	}

	if (aux == get_TeamsNumber())
		return true;
	else
		return false;
}

/**
 * @brief      Selects the algorythm which is going to be used
 */
void Calendar::algorythmSelector (void) {
	if (isPow2())
		generateCalendarPow2(0, get_TeamsNumber() - 1);
	else {
		std::cout << std::endl << "Actualmente solo está disponible el algoritmo para potencias en base 2, disculpe las molestias." << std::endl;
		exit(0);
		generateCalendar();
	}
}

/**
 * @brief      Generates the competition calendar
 *
 * @param[in]  i     Position i
 * @param[in]  j     Position j
 */
void Calendar::generateCalendarPow2 (int i, int j) {
	if ((j - i) == 1) {	
		// Play between themselves the same day
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

/**
 * @brief      Rotates the solution previously generated
 *
 * @param[in]  team1        The lower team
 * @param[in]  team2        The higher team
 * @param[in]  day1         The lower day
 * @param[in]  day2         The higher day
 * @param[in]  starterTeam  The starter team
 */
void Calendar::rotateSolution (int team1, int team2, int day1, int day2, int starterTeam) {
	for (int i = day1; i <= day2; i++)
		calendar_[team1][i] = starterTeam + i - day1 + 1;

	for (int i = team1 + 1; i <= team2; i++) {
		calendar_[i][day1] = calendar_[i - 1][day2];
		for (int j = day1 + 1; j <= day2; j++) 
			calendar_[i][j] = calendar_[i - 1][j - 1];
	}
}

void Calendar::generateCalendar (void) {

}

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os        The output stream
 * @param[in]  calendar  The calendar
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator << (std::ostream& os, const Calendar& calendar) {
	os << std::endl << std::endl;
	for (int i = 0; i < calendar.teamsNumber_ - 1; i++)
		os <<"\tDay " << i + 1; 

	os << std::endl << std::endl;
	for (int i = 0; i < calendar.teams_.size(); i++) {
		os << calendar.teams_[i] << "\t";
		for (int j = 1; j < calendar.teams_.size(); j++) 
			os << calendar.calendar_[i][j] << '\t';

		os << std::endl;
	}
	return os;
}

/**
 * @brief      Prints the Calendar on screen
 *
 * @param      os    The output stream
 */
void Calendar::write(std::ostream& os) {
	os << *this;
}



  




	 