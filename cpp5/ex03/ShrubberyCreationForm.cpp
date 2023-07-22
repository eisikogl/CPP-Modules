#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), _target(copy._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm &assign)
{
    (void)assign;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery Creation Form", 145, 137), _target(target)
{

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->isSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::string file_name = this->getName().append("_shrubbery");
    std::ofstream out_file(file_name.c_str());
    out_file << "          .     .  .      +     .      .          ."                 << std::endl;
    out_file << "     .       .      .     #       .           ."                     << std::endl;
    out_file << "        .      .         ###            .      .      ."             << std::endl;
    out_file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ."                   << std::endl;
    out_file << "          .      . \"####\"###\"####\"  .\n"                         << std::endl;
    out_file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ."    << std::endl;
    out_file << "  .             \"#########\"#########\"        .        ."          << std::endl;
    out_file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ."          << std::endl;
    out_file << "     .     .  \"#######\"\"##\"##\"#######\"                  ."     << std::endl;
    out_file << "                .\"##\"#####\"#####\"##\"           .      ."        << std::endl;
    out_file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ."            << std::endl;
    out_file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ."        << std::endl;
    out_file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ."            << std::endl;
    out_file << "            .     \"      000      \"    .     ."                    << std::endl;
    out_file.close();
}
