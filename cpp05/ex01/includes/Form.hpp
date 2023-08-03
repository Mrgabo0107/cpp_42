#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		Form(const Form &src);

		~Form();

		Form &operator=(const Form &rhs);

		const std::string	&getName() const;
		const bool			&isSigned() const;
		const unsigned int	&getGradeToSign() const;
		const unsigned int	&getGradeToExecute() const;
		
		void				beSigned(Bureaucrat const &candidate) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */