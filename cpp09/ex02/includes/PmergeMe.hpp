/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:29:44 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/20 17:30:30 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <climits>
# include <iterator> 
# include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe(int ac, char** ag);
		PmergeMe(PmergeMe const&src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);

		typedef std::vector<std::vector<unsigned int> >	VecOfVecs;
		typedef std::deque<std::deque<unsigned int> >	DeqOfDeqs;
		typedef std::vector<unsigned int>				Vect;
		typedef std::deque<unsigned int>				Dequ;

		const VecOfVecs&	getInitVec() const;
		const DeqOfDeqs&	getInitDeq() const;
		const VecOfVecs&	getVecRet() const;
		const DeqOfDeqs&	getDeqRet() const;
		char**&				getAg();
		int					getAc();
}

		bool	solve();

	private:
		int										_ac;
		char**									_ag;
		std::vector<std::vector<unsigned int> >	_initVec;
		std::deque<std::deque<unsigned int> >	_initDeq;
		std::vector<std::vector<unsigned int> >	_vecRet;
		std::deque<std::deque<unsigned int> >	_deqRet;
		long long								_timeVec;
		long long								_timeDeq;

		size_t		twoPow(size_t exp);
		size_t		criticalIndex(size_t compCtrl);
		size_t		numElemToCompare(const size_t mainChainSize, const size_t compCtrl);
		long long	elapsedTimeMicroSec(struct timeval start, struct timeval end);

		bool						solveVector(char** ag);
		bool						parseAndFillVector(char ** ag);
		VecOfVecs					FordJhonsonAlgorithmVec(const VecOfVecs& Vec);
		VecOfVecs					MergeVec(const VecOfVecs& Vec);
		VecOfVecs					FirstMatchVec(const VecOfVecs& vec);
		VecOfVecs					InsertVec(const VecOfVecs& Vec);
		VecOfVecs					insertWinnersVec(const VecOfVecs& Vec, size_t pairLength);
		Vect						firstVecHalf(const Vect& normalVec);
		Vect						secondVecHalf(const Vect& normalVec);
		void						insertLosersVec(VecOfVecs& mainChain, const VecOfVecs& Vec, const size_t PairLength, const size_t critIndex, const size_t compCtrl, const size_t indexMax);
		VecOfVecs::const_iterator	startIteratorVec(const VecOfVecs& Vec, const size_t compCtrl, const size_t indexMax);
		VecOfVecs::const_iterator	getVecIteratorFromIndex(const VecOfVecs& Vec, size_t index);
		void						AdaptedSteinhausInsertionVec(VecOfVecs& mainChain, VecOfVecs::iterator& low, VecOfVecs::iterator& high, const Vect& VToInsert);

		bool						solveDeque(char** ag);
		bool						parseAndFillDeque(char** ag);
		DeqOfDeqs					FordJhonsonAlgorithmDeq(const DeqOfDeqs& Deq);
		DeqOfDeqs					MergeDeq(const DeqOfDeqs& Deq);
		DeqOfDeqs					FirstMatchDeq(const DeqOfDeqs& Deq);
		DeqOfDeqs					InsertDeq(const DeqOfDeqs& Deq);
		DeqOfDeqs					insertWinnersDeq(const DeqOfDeqs& Deq, size_t pairLength);
		Dequ						firstDeqHalf(const Dequ& normalDeq);
		Dequ						secondDeqHalf(const Dequ& normalDeq);
		void						insertLosersDeq(DeqOfDeqs& mainChain, const DeqOfDeqs& Deq, const size_t PairLength, const size_t critIndex, const size_t compCtrl, const size_t indexMax);
		DeqOfDeqs::const_iterator	startIteratorDeq(const DeqOfDeqs& Deq, const size_t compCtrl, const size_t indexMax);
		DeqOfDeqs::const_iterator	getDeqIteratorFromIndex(const DeqOfDeqs& Deq, size_t index);
		void						AdaptedSteinhausInsertionDeq(DeqOfDeqs& mainChain, DeqOfDeqs::iterator& low, DeqOfDeqs::iterator& high, const Dequ& DToInsert);
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);

#endif /* ******************************************************** PMERGEME_H */