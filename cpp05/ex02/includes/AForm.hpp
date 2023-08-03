#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{

	public:

		AForm(const std::string name, const std::string target, \
		const unsigned int gradeToSign, const unsigned int gradeToExecute);
		AForm(const AForm &src);
		
		virtual ~AForm();

		AForm &operator=(const AForm &rhs);

		const std::string	&getName() const;
		const std::string	&getTarget() const;
		const bool			&isSigned() const;
		const unsigned int	&getGradeToSign() const;
		const unsigned int	&getGradeToExecute() const;
		void setName(std::string name) const;
		void setTarget(std::string target) const;
		void setSigned(bool isSigned);
		void setGradeToSign(unsigned int gradeToSign) const;
		void setGradeToExecute(unsigned int gradeToExecute) const;
		
		void				beSigned(Bureaucrat const &candidate) const;
		void				execute(Bureaucrat const &executor) const;
		virtual void		action() const = 0;

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
		class notSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif /* ************************************************************ FORM_H */