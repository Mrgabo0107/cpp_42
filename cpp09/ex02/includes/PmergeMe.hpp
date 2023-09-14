/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:29:44 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/14 16:06:07 by gamoreno         ###   ########.fr       */
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

class PmergeMe
{
	public:
		PmergeMe(int ac, char** ag);
		PmergeMe(PmergeMe const&src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);

		typedef const std::vector< std::vector<unsigned int> > VectorOfVectors;
		typedef const std::deque< std::deque<unsigned int> > DequeOfDeques;

		VectorOfVectors&	getinitVec() const;
		DequeOfDeques&		getinitDeq() const;
		char**&				getAg();
		int					getAc();

		bool	solve();

	private:
		int											_ac;
		char**										_ag;
		std::vector< std::vector<unsigned int> >	_initVec;
		std::deque< std::deque<unsigned int> >		_initDeq;
		std::vector< std::vector<unsigned int> >	_vecRet;
		std::deque< std::deque<unsigned int> >		_deqRet;

		bool			solveVector(char** ag);
		bool			parseAndFillVector(char ** ag);
		VectorOfVectors	FordJhonsonAlgorithmVec(const VectorOfVectors& Vec);
		VectorOfVectors	CompareSortAndMatchVec(const VectorOfVectors& Vec);
		VectorOfVectors	FirstMatchVec(const VectorOfVectors& vec);
		VectorOfVectors	SteinhausInsertionVec(const VectorOfVectors& Vec);


		bool			solveDeque(char** ag);
		bool			parseAndFillDeque(char** ag);
		DequeOfDeques	FordJhonsonAlgorithmDeq(const DequeOfDeques& Deq);
		DequeOfDeques	CompareSortAndMatchDeq(const DequeOfDeques& Deq);
		DequeOfDeques	FirstMatchDeq(const DequeOfDeques& Deq);,
		DequeOfDeques	SteinhausInsertionDeq(const DequeOfDeques& Deq);
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);

#endif /* ******************************************************** PMERGEME_H */