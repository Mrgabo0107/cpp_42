#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm("ShrubberyCreationForm", src.getTarget(), 145, 137)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		this->AForm::setName(rhs.AForm::getName());
		this->AForm::setTarget(rhs.AForm::getTarget());
		this->AForm::setSigned(rhs.AForm::isSigned());
		this->AForm::setGradeToSign(rhs.AForm::getGradeToSign());
		this->AForm::setGradeToExecute(rhs.AForm::getGradeToExecute());
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::action() const
{
    std::ofstream	outfile;
	std::string		filename = this->getTarget() + "_shrubbery";

	outfile.open(filename.c_str());
	if (outfile.is_open())
    {
	    outfile << "\n" 
		<<"               ,@@@@@@@,\n"
		<<"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<<"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<<"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<<"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<<"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		<<"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<<"       |o|        | |         | |\n"
		<<"       |.|        | |         | |\n"
		<<"    \\/ ._\\______/  ,\\_______/.  \\___ \n"
		<< std::endl;
    	outfile.close();
	}
	else
		std::cerr << "error creating tree file\n";
}

/* ************************************************************************** */
