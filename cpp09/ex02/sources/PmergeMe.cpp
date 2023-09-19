/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:29:42 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/19 15:28:37by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(int ac, char** ag) : _ac(ac), _ag(ag) {}

PmergeMe::PmergeMe(PmergeMe const &src) : _ac(src._ac), _ag(src._ag),
_initVec(src._initVec), _initDeq(src._initDeq), _vecRet(src._vecRet),
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

size_t	PmergeMe::twoPow(size_t exp) {
	size_t	i = 0;
	size_t	ret = 1;

	while (i < exp) {
		ret *= 2;
		++i;
	}
	return ret;
}

size_t	PmergeMe::criticalIndex(size_t compCtrl) {
	if (compCtrl == 1)
		return 0;
	else
		return (PmergeMe::twoPow(compCtrl) - 2 -criticalIndex(compCtrl - 1));
}

size_t	PmergeMe::numElemToCompare(const size_t mainChainSize, const size_t compCtrl) {
	size_t	optimalNumbOfElem = PmergeMe::twoPow(compCtrl) - 1;
	if (optimalNumbOfElem > mainChainSize)
		return (mainChainSize);
	return (optimalNumbOfElem);
}

//Vector
bool	PmergeMe::solveVector(char** ag) {
	if(!PmergeMe::parseAndFillVector(ag))
		return false;
	_vecRet = PmergeMe::FordJhonsonAlgorithmVec(_initVec);
	return true;
}

bool PmergeMe::parseAndFillVector(char **ag) {
	_initVec.clear();

	for (char** arg = ++ag; *arg != NULL; ++arg) {
		char* endptr;
		long int value = std::strtol(*arg, &endptr, 10);

		if (*endptr == '\0' && 0 < value && value <= UINT_MAX) {
			Vect unitVector;
			unitVector.push_back(static_cast<unsigned int>(value));
			_initVec.push_back(unitVector);
		} else {
			std::cerr << "Error: \"" << *arg << "\" is not a valid positive integer" << std::endl;
			return false;
		}
	}
	return true;
}

PmergeMe::VecOfVecs	PmergeMe::FirstMatchVec(const VecOfVecs& Vec) {
	PmergeMe::VecOfVecs	tempVec = Vec;
	PmergeMe::VecOfVecs	retVec;
	
	while (tempVec.size() >= 2) {
		VecOfVecs::const_iterator it1 = tempVec.begin();
		VecOfVecs::const_iterator it2 = it1 + 1;

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

PmergeMe::VecOfVecs::const_iterator PmergeMe::getVecIteratorFromIndex(const PmergeMe::VecOfVecs& Vec, size_t index) {
	if (index < Vec.size()) {
		PmergeMe::VecOfVecs::const_iterator it = Vec.begin() + index;
		return it;
	}
	else {
		return Vec.end();
	}
}



PmergeMe::Vect	PmergeMe::firstVecHalf(const Vect& normalVec) {
	Vect	retVec(normalVec.begin(), normalVec.begin() + (normalVec.size() / 2));
	
	return (retVec);
}

PmergeMe::Vect	PmergeMe::secondVecHalf(const Vect& normalVec) {
	Vect	retVec(normalVec.begin() + (normalVec.size() / 2), normalVec.end());

	return (retVec);
}

PmergeMe::VecOfVecs::const_iterator	PmergeMe::startIteratorVec(const VecOfVecs& Vec,
	const size_t compCtrl, const size_t indexMax) {
	size_t	nextCritIndex = PmergeMe::criticalIndex(compCtrl + 1);
	if (nextCritIndex > indexMax)
		return PmergeMe::getVecIteratorFromIndex(Vec, indexMax);
	return PmergeMe::getVecIteratorFromIndex(Vec, nextCritIndex);
}

void	PmergeMe::AdaptedSteinhausInsertionVec(VecOfVecs& mainChain, VecOfVecs::iterator& low,
			VecOfVecs::iterator& high, const Vect& VToInsert) {
	if (std::distance(low, high) > 0) {
		if ((std::distance(low, high) + 1) % 2 == 0) {
			VecOfVecs::iterator aux1 = low + (std::distance(low, high) / 2);
			VecOfVecs::iterator aux2 = aux1 + 1;
			if (VToInsert[0] > ((*aux1)[0] + (*aux2)[0]) / 2)
				low = aux2;
			else
				high = aux1;
		}
		else {
			VecOfVecs::iterator aux = low + (std::distance(low, high) / 2);
			if (VToInsert[0] > (*aux)[0])
				low = aux + 1;
			else
				high = aux - 1;
		}
		PmergeMe::AdaptedSteinhausInsertionVec(mainChain, low, high, VToInsert);
	}
	else {
		if (VToInsert[0] > (*low)[0])
			mainChain.insert(low + 1, VToInsert);
		else
			mainChain.insert(low, VToInsert);
	}
}

void	PmergeMe::insertLosersVec(VecOfVecs& mainChain,	const VecOfVecs& Vec,
		const size_t PairLength, const size_t critIndex, const size_t compCtrl,
			const size_t indexMax) {
	VecOfVecs::const_iterator	startIt = PmergeMe::startIteratorVec(Vec, compCtrl, indexMax);
	VecOfVecs::const_iterator	endIt = PmergeMe::getVecIteratorFromIndex(Vec, critIndex);
	size_t						numElemToCompare = PmergeMe::numElemToCompare(mainChain.size(), compCtrl + 1);

	if (startIt == Vec.end() - 1 && (*startIt).size() < PairLength) {
		VecOfVecs::iterator low = mainChain.begin();
		VecOfVecs::iterator high = mainChain.begin() + numElemToCompare - 1;
		
		PmergeMe::AdaptedSteinhausInsertionVec(mainChain, low, high, *startIt);
		--startIt;
	}
	for (; startIt != endIt; --startIt) {
		VecOfVecs::iterator low = mainChain.begin();
		VecOfVecs::iterator high = mainChain.begin() + numElemToCompare - 1;
		
		PmergeMe::AdaptedSteinhausInsertionVec(mainChain, low, high, PmergeMe::secondVecHalf(*startIt));
	}
}

PmergeMe::VecOfVecs	PmergeMe::insertWinnersVec(const VecOfVecs& Vec, size_t pairLength) {
	PmergeMe::VecOfVecs retVec;
	PmergeMe::VecOfVecs::const_iterator it = Vec.begin();

	retVec.push_back(PmergeMe::secondVecHalf(*it));
	retVec.push_back(PmergeMe::firstVecHalf(*it));
	++it;
	for (; it < Vec.end() - 1; ++it) {
		retVec.push_back(PmergeMe::firstVecHalf(*it));
	}
	if(it < Vec.end() && (*it).size() < pairLength) {
		return retVec;
	}
	if (it < Vec.end())
		retVec.push_back(PmergeMe::firstVecHalf(*it));

	return retVec;
}

PmergeMe::VecOfVecs	PmergeMe::InsertVec(const VecOfVecs& Vec) {
	size_t				compCtrl = 1;
	size_t				indexMax = Vec.size() - 1;
	size_t				pairLength = Vec[0].size();
	size_t				critIndex = PmergeMe::criticalIndex(compCtrl);
	PmergeMe::VecOfVecs	mainChain = PmergeMe::insertWinnersVec(Vec, pairLength);
	
	
	while (indexMax > critIndex) {
		PmergeMe::insertLosersVec(mainChain, Vec, pairLength, critIndex, compCtrl, indexMax);
		compCtrl++;
		critIndex = PmergeMe::criticalIndex(compCtrl);
	}
	return mainChain;
}

PmergeMe::VecOfVecs	PmergeMe::MergeVec(const VecOfVecs& Vec) {
	PmergeMe::VecOfVecs	firstMatch = FirstMatchVec(Vec);
	PmergeMe::VecOfVecs	retVec;
	
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

PmergeMe::VecOfVecs	PmergeMe::FordJhonsonAlgorithmVec(const VecOfVecs& Vec) {
	if (Vec.size() == 0) {
		PmergeMe::VecOfVecs empty;
		return (empty);
	}
	else if (Vec.size() == 1)
		return (Vec);
	PmergeMe::VecOfVecs VecOfPairs = PmergeMe::MergeVec(Vec);
	return(PmergeMe::InsertVec(VecOfPairs));
}

//Deque
bool	PmergeMe::solveDeque(char** ag) {
	if(!PmergeMe::parseAndFillDeque(ag))
		return false;
	_deqRet = PmergeMe::FordJhonsonAlgorithmDeq(_initDeq);
	return true;
}

bool PmergeMe::parseAndFillDeque(char** ag) {
	_initDeq.clear();

	for (char** arg = ++ag; *arg != NULL; ++arg) {
		char* endptr;
		long int value = std::strtol(*arg, &endptr, 10);	

		if (*endptr == '\0' &&  0 < value && value <= UINT_MAX) {
			Dequ unitDeque;
			unitDeque.push_back(static_cast<unsigned int>(value));
			_initDeq.push_back(unitDeque);
		} else {
			std::cerr << "Error: \"" << *arg << "\" is not a valid positive integer" << std::endl;
			return false;
		}
	}
	return true;
}

PmergeMe::DeqOfDeqs	PmergeMe::FirstMatchDeq(const DeqOfDeqs& Deq) {
	PmergeMe::DeqOfDeqs tempDeq = Deq;
	PmergeMe::DeqOfDeqs retDeq;

	while (tempDeq.size() >= 2) {
		DeqOfDeqs::const_iterator it1 = tempDeq.begin();
		DeqOfDeqs::const_iterator it2 = it1 + 1;

		if ((*it1)[0] >= (*it2)[0]) {
			Dequ aux;
		
			aux.insert(aux.end(), it1->begin(), it1->end());
			aux.insert(aux.end(), it2->begin(), it2->end());
			retDeq.push_back(aux);
		}
		else {
			Dequ aux;

			aux.insert(aux.end(), it2->begin(), it2->end());
			aux.insert(aux.end(), it1->begin(), it1->end());
			retDeq.push_back(aux);
		}
		tempDeq.erase(tempDeq.begin(), tempDeq.begin() + 2);
	}
	if (!tempDeq.empty()) {
		retDeq.push_back(tempDeq[0]);
	}
	return retDeq;
}

PmergeMe::DeqOfDeqs::const_iterator	PmergeMe::getDeqIteratorFromIndex(const PmergeMe::DeqOfDeqs& Deq, size_t index) {
	if (index < Deq.size()) {
		PmergeMe::DeqOfDeqs::const_iterator it = Deq.begin() + index;
		return it;
	}
	else {
		return Deq.end();
	}
}


PmergeMe::Dequ	PmergeMe::firstDeqHalf(const Dequ& normalDeq) {
	Dequ	retDeq(normalDeq.begin(), normalDeq.begin() + (normalDeq.size() / 2));
		
	return (retDeq);
}

PmergeMe::Dequ	PmergeMe::secondDeqHalf(const Dequ& normalDeq) {
	Dequ	retDeq(normalDeq.begin() + (normalDeq.size() / 2), normalDeq.end());

	return (retDeq);
}

PmergeMe::DeqOfDeqs::const_iterator	PmergeMe::startIteratorDeq(const DeqOfDeqs& Deq,
	const size_t compCtrl, const size_t indexMax) {
	size_t	nextCritIndex = PmergeMe::criticalIndex(compCtrl + 1);
	if (nextCritIndex > indexMax)
		return PmergeMe::getDeqIteratorFromIndex(Deq, indexMax);
	return PmergeMe::getDeqIteratorFromIndex(Deq, nextCritIndex);
}

void	PmergeMe::AdaptedSteinhausInsertionDeq(DeqOfDeqs& mainChain, DeqOfDeqs::iterator& low,
			DeqOfDeqs::iterator& high, const Dequ& DToInsert) {
	if (std::distance(low, high) > 0) {
		if ((std::distance(low, high) + 1) % 2 == 0) {
			DeqOfDeqs::iterator aux1 = low + (std::distance(low, high) / 2);
			DeqOfDeqs::iterator aux2 = aux1 + 1;
			if (DToInsert[0] > ((*aux1)[0] + (*aux2)[0]) / 2)
				low = aux2;
			else
				high = aux1;
		}
		else {
			DeqOfDeqs::iterator aux = low + (std::distance(low, high) / 2);
			if (DToInsert[0] > (*aux)[0])
				low = aux + 1;
			else
				high = aux - 1;
		}
		PmergeMe::AdaptedSteinhausInsertionDeq(mainChain, low, high, DToInsert);
	}
	else {
		if (DToInsert[0] > (*low)[0])
			mainChain.insert(low + 1, DToInsert);
		else
			mainChain.insert(low, DToInsert);
	}
}

void	PmergeMe::insertLosersDeq(DeqOfDeqs& mainChain,	const DeqOfDeqs& Deq,
		const size_t PairLength, const size_t critIndex, const size_t compCtrl,
			const size_t indexMax) {
	DeqOfDeqs::const_iterator	startIt = PmergeMe::startIteratorDeq(Deq, compCtrl, indexMax);
	DeqOfDeqs::const_iterator	endIt = PmergeMe::getDeqIteratorFromIndex(Deq, critIndex);
	size_t						numElemToCompare = PmergeMe::numElemToCompare(mainChain.size(), compCtrl + 1);

	if (startIt == Deq.end() - 1 && (*startIt).size() < PairLength) {
		DeqOfDeqs::iterator low = mainChain.begin();
		DeqOfDeqs::iterator high = mainChain.begin() + numElemToCompare - 1;
		
		PmergeMe::AdaptedSteinhausInsertionDeq(mainChain, low, high, (*startIt));
		--startIt;
	}
	for (; startIt != endIt; --startIt) {
		DeqOfDeqs::iterator low = mainChain.begin();
		DeqOfDeqs::iterator high = mainChain.begin() + numElemToCompare - 1;
		
		PmergeMe::AdaptedSteinhausInsertionDeq(mainChain, low, high, PmergeMe::secondDeqHalf(*startIt));
	}
}

PmergeMe::DeqOfDeqs	PmergeMe::insertWinnersDeq(const DeqOfDeqs& Deq, size_t pairLength) {
	PmergeMe::DeqOfDeqs retDeq;
	PmergeMe::DeqOfDeqs::const_iterator it = Deq.begin();

	retDeq.push_back(PmergeMe::secondDeqHalf(*it));
	retDeq.push_back(PmergeMe::firstDeqHalf(*it));
	++it;
	for (; it < Deq.end() - 1; ++it) {
		retDeq.push_back(PmergeMe::firstDeqHalf(*it));
	}
	if (it < Deq.end() && (*it).size() < pairLength) {
		return retDeq;
	}
	if (it < Deq.end())
		retDeq.push_back(PmergeMe::firstDeqHalf(*it));

	return retDeq;
}

PmergeMe::DeqOfDeqs	PmergeMe::InsertDeq(const DeqOfDeqs& Deq) {
	size_t				compCtrl = 1;
	size_t				indexMax = Deq.size() - 1;
	size_t				pairLength = Deq[0].size();
	size_t				critIndex = PmergeMe::criticalIndex(compCtrl);
	PmergeMe::DeqOfDeqs	mainChain = PmergeMe::insertWinnersDeq(Deq, pairLength);
	
	
	while (indexMax > critIndex) {
		PmergeMe::insertLosersDeq(mainChain, Deq, pairLength, critIndex, compCtrl, indexMax);
		compCtrl++;
		critIndex = PmergeMe::criticalIndex(compCtrl);
	}
	return mainChain;
}

PmergeMe::DeqOfDeqs	PmergeMe::MergeDeq(const DeqOfDeqs& Deq) {
	PmergeMe::DeqOfDeqs	firstMatch = FirstMatchDeq(Deq);
	PmergeMe::DeqOfDeqs	retDeq;
	
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

PmergeMe::DeqOfDeqs	PmergeMe::FordJhonsonAlgorithmDeq(const DeqOfDeqs& Deq) {
	if (Deq.size() == 0) {
		PmergeMe::DeqOfDeqs empty;
		return (empty);
	}
	else if (Deq.size() == 1)
		return (Deq);
	PmergeMe::DeqOfDeqs DeqOfPairs = PmergeMe::MergeDeq(Deq);
	return (PmergeMe::InsertDeq(DeqOfPairs));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const PmergeMe::VecOfVecs& PmergeMe::getInitVec() const {
	return _initVec;
}

const PmergeMe::DeqOfDeqs& PmergeMe::getInitDeq() const {
	return _initDeq;
}

const PmergeMe::VecOfVecs& PmergeMe::getVecRet() const {
	return _vecRet;
}

const PmergeMe::DeqOfDeqs& PmergeMe::getDeqRet() const {
	return _deqRet;
}


char**& PmergeMe::getAg() {
	return _ag;
}


int PmergeMe::getAc() {
	return _ac;
}


// For Debbug
// void	PmergeMe::printVecOfVecs(const VecOfVecs& Vec) {
// 	PmergeMe::VecOfVecs::const_iterator itv = Vec.begin();
// 	std::cout << "Vector values: {";
	
// 	while (itv != Vec.end()) {
// 		Vect::const_iterator inner_itv = itv->begin();
// 		std::cout << "{";
// 		while (inner_itv != itv->end()) {
// 			std::cout << " " << *inner_itv << " ";
// 			++inner_itv;
// 		}
// 		std::cout << "}";
// 		++itv;
// 	}
// 	std::cout << "}";
// }
/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, PmergeMe const &i)
{
	{
	PmergeMe::VecOfVecs::const_iterator itv = i.getInitVec().begin();
	o << "Vector init: {";
	
	while (itv != i.getInitVec().end()) {
		PmergeMe::Vect::const_iterator inner_itv = itv->begin();
		o << "{";
		while (inner_itv != itv->end()) {
			o << " " << *inner_itv << " ";
			++inner_itv;
		}
		o << "}";
		++itv;
	}
	o << "}";

	PmergeMe::DeqOfDeqs::const_iterator itd = i.getInitDeq().begin();
    o << "\n\nDeque init: {";

    while (itd != i.getInitDeq().end()) {
        PmergeMe::Dequ::const_iterator inner_itd = itd->begin();
        o << "{";
        while (inner_itd != itd->end()) {
            o << " " << *inner_itd << " ";
            ++inner_itd;
        }
        o << "}";
        ++itd;
    }
    o << "}";
	}
	{
	PmergeMe::VecOfVecs::const_iterator itv = i.getVecRet().begin();
	o << "\nVector values: {";
	
	while (itv != i.getVecRet().end()) {
		PmergeMe::Vect::const_iterator inner_itv = itv->begin();
		o << "{";
		while (inner_itv != itv->end()) {
			o << " " << *inner_itv << " ";
			++inner_itv;
		}
		o << "}";
		++itv;
	}
	o << "}";

	PmergeMe::DeqOfDeqs::const_iterator itd = i.getDeqRet().begin();
    o << "\n\nDeque values: {";

    while (itd != i.getDeqRet().end()) {
        PmergeMe::Dequ::const_iterator inner_itd = itd->begin();
        o << "{";
        while (inner_itd != itd->end()) {
            o << " " << *inner_itd << " ";
            ++inner_itd;
        }
        o << "}";
        ++itd;
    }
	}
	return o;
}



/* ************************************************************************** */