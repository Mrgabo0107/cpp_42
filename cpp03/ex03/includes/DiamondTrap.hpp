#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include <climits>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{

	public:
		//Constructors
		DiamondTrap();
		DiamondTrap(std::string newName);
		DiamondTrap(const DiamondTrap &src);
		
		//Assignation
		DiamondTrap&	operator=(DiamondTrap const &rhs);
		
		//Destructor
		~DiamondTrap();

		//Methods
		void attack(const std::string &target);
		void whoAmI(void);

	private:
		std::string	_name;

};

std::ostream&	operator<<(std::ostream &o, DiamondTrap const &i);

#endif /* ***************************************************** DIAMONDTRAP_H */