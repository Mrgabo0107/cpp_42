/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:29:42 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/14 17:15:32 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(int ac, char** ag) : _ac(ac), _ag(ag) {}

PmergeMe::PmergeMe(PmergeMe const &src) : _ac(src._ac), _ag(src._ag),
_initVec(src._initVec), _initDeq(src._initDeq), _vecRet(src.vecRet),
_deqRet(src._deqRet) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- ASSIGN ------------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs) {
		_ac = rhs._ac;
		_ag = rhs._ag;
		_initVec = rhs._initVec;
		_initDeq = rhs._initDeq;
		_vecRet = rhs._vecRet;
		_deqRet = rhs._deqRet;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool	PmergeMe::solve() {
	char** agCopy = _ag;

	if (PmergeMe::solveDeque(agCopy) && PmergeMe::solveVector(agCopy))
		return true;
	return false;
}

//Vector
bool	PmergeMe::solveVector(char** ag) {
	if(!PmergeMe::parseAndFillVector(ag))
		return false;
	_retVec = PmergeMe::FordJhonsonAlgorithmVec(_initVec);
	return true;
}

bool PmergeMe::parseAndFillVector(char **ag) {
	_initVec.clear();

	for (char** arg = ++ag; *arg != NULL; ++arg) {
		char* endptr;
		long int value = std::strtol(*arg, &endptr, 10);

		if (*endptr == '\0' && 0 < value && value <= UINT_MAX) {
			std::vector<unsigned int> unitVector;
			unitVector.push_back(static_cast<unsigned int>(value));
			_initVec.push_back(unitVector);
		} else {
			std::cerr << "Error: \"" << *arg << "\" is not a valid positive integer" << std::endl;
			return false;
		}
	}
	return true;
}

VectorOfVectors	PmergeMe::FirstMatchVec(const VectorOfVectors& Vec) {
	VectorOfVectors	tempVec = Vec;
	VectorOfVectors	retVec;
	
	while (tempVec.size() >= 2) {
		VectorOfVectors::iterator it1 = tempVec.begin();
		VectorOfVectors::iterator it2 = ++it1;

		if((*it1)[0] >= (*it2)[0]) {
			std::vector <unsigned int> aux;
			
			aux.insert(aux.end(), it1->begin(), it1->end());
			aux.insert(aux.end(), it2->begin(), it2->end());
			retVec.push_back(aux);
		}
		else {
			std::vector <unsigned int> aux;
			
			aux.insert(aux.end(), it2->begin(), it2->end());
			aux.insert(aux.end(), it1->begin(), it1->end());
			retVec.push_back(aux);
		}
		tempVec.erase(tempVec.begin(), tempVec.begin() + 2);
	}
	if (!tempVec.empty()) {
		retVec.push_back(tempVec[0]);
	}
	return retVec;
}

VectorOfVectors	PmergeMe::CompareSortAndMatchVec(const VectorOfVectors& Vec) {
	VectorOfVectors	firstMatch = FirstMatchVec(Vec);
	vectorOfVectors	retVec;
	
	if (Vec.size() % 2 == 0) {
		retVec = PmergeMe::FordJhonsonAlgorithmVec(firstMatch);
	}
	else {
		std::vector <unsigned int> aux = firstMatch.back();
		firstMatch.pop_back();
		retVec = PmergeMe::FordJhonsonAlgorithmVec(firstMatch);
		retVec.push_back(aux);
	}
	return retVec;
}

VectorOfVectors PmergeMe::SteinhausInsertionVec(const VectorOfVectors& Vec) {
	
}

VectorOfVectors	PmergeMe::FordJhonsonAlgorithmVec(const VectorOfVectors& Vec) {
	VectorOfVectors VecOfPairs = PmergeMe::CompareSortAndMatchVec(Vec);
	return(PmergeMe::SteinhausInsertionVec(vecOfPairs));
}

//Deque
bool	PmergeMe::solveDeque(char** ag) {
	if(!PmergeMe::parseAndFillDeque(ag))
		return false;
	_retDeq = PmergeMe::FordJhonsonAlgorithmVec(_initDeq);
	return true;
}

bool PmergeMe::parseAndFillDeque(char** ag) {
	_initDeq.clear();

	for (char** arg = ++ag; *arg != NULL; ++arg) {
		char* endptr;
		long int value = std::strtol(*arg, &endptr, 10);	

		if (*endptr == '\0' &&  0 < value && value <= UINT_MAX) {
			std::deque<unsigned int> unitDeque;
			unitDeque.push_back(static_cast<unsigned int>(value));
			_initDeq.push_back(unitDeque);
		} else {
			std::cerr << "Error: \"" << *arg << "\" is not a valid positive integer" << std::endl;
			return false;
		}
	}
	return true;
}

DequeOfDeques	PmergeMe::FirstMatchDeq(const DequeOfDeques& Deq) {
	DequeOfDeques tempDeq = Deq;
	DequeOfDeques retDeq;

	while (tempDeq.size() >= 2) {
		DequeOfDeques::iterator it1 = tempDeq.begin();
		DequeOfDeques::iterator it2 = ++it1;

		if ((*it1)[0] >= (*it2)[0]) {
			std::deque<unsigned int> aux;
		
			aux.insert(aux.end(), it1->begin(), it1->end());
			aux.insert(aux.end(), it2->begin(), it2->end());
			retDeq.push_back(aux);
		}
		else {
			std::deque<unsigned int> aux;

			aux.insert(aux.end(), it2->begin(), it2->end());
			aux.insert(aux.end(), it1->begin(), it1->end());
			retDeq.push_back(aux);
		}
		tempDeq.erase(tempDeq.begin(), std::next(tempDeq.begin(), 2));
	}
	if (!tempDeq.empty()) {
		retDeq.push_back(tempDeq[0]);
	}
	return retDeq;
}

DequeOfDeques	PmergeMe::CompareSortAndMatchDeq(const DequeOfDeques& Deq) {
	DequeOfDeques	firstMatch = FirstMatchDeq(Deq);
	DequeOfDeques	retDeq;
	
	if (Deq.size() % 2 == 0) {
		retDeq = PmergeMe::FordJhonsonAlgorithmDeq(firstMatch);
	}
	else {
		std::deque <unsigned int> aux = firstMatch.back();
		firstMatch.pop_back();
		retDeq = PmergeMe::FordJhonsonAlgorithmDeq(firstMatch);
		retDeq.push_back(aux);
	}
	return retDeq;
}

DequeOfDeques	PmergeMe::SteinhausInsertionDneq(const DequeOfDeques& Deq) {
	
}


DequeOfDeques	PmergeMe::FordJhonsonAlgorithmDeq(const DequeOfDeques& Deq) {
	DequeOfDeques DeqOfPairs = PmergeMe::compareSortAndMatchDeq(Deq);
	return (PmergeMe::SteinhausInsertionDeq(DeqOfPairs));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

PmergeMe::VectorOfVectors& PmergeMe::getinitVec() const {
	return _initVec;
}

PmergeMe::DequeOfDeques& PmergeMe::getinitDeq() const {
	return _initDeq;
}


char**& PmergeMe::getAg() {
	return _ag;
}


int PmergeMe::getAc() {
	return _ac;
}

/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, PmergeMe const &i)
{
	PmergeMe::VectorOfVectors::const_iterator itv = i.getinitVec().begin();
	o << "Vector values: {";
	
	while (itv != i.getinitVec().end()) {
		std::vector<unsigned int>::const_iterator inner_itv = itv->begin();
		o << "{";
		while (inner_itv != itv->end()) {
			o << " " << *inner_itv << " ";
			++inner_itv;
		}
		o << "}";
		++itv;
	}
	o << "}";

	PmergeMe::DequeOfDeques::const_iterator itd = i.getinitDeq().begin();
    o << "\n\nDeque values: {";

    while (itd != i.getinitDeq().end()) {
        std::deque<unsigned int>::const_iterator inner_itd = itd->begin();
        o << "{";
        while (inner_itd != itd->end()) {
            o << " " << *inner_itd << " ";
            ++inner_itd;
        }
        o << "}";
        ++itd;
    }
    o << "}";
	return o;
}



/* ************************************************************************** */