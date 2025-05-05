/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:25:01 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/05 13:52:59 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "A AForm (default) spawned!" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	(void) copy;
	*this = copy;
}

AForm &AForm::operator=(const AForm &obj)
{
	(void) obj;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "A AForm despawned!" << std::endl;
}

AForm::AForm(const std::string &name, const int &signGrade, const int &execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "A AForm (" << name << ") spawned!" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_signGrade == 0 || _execGrade == 0)
		throw AForm::GradeTooHighException();
}

const std::string &AForm::getName() const
{
	return (_name);
}

const bool &AForm::isSigned() const
{
	return (_signed);
}

const unsigned char &AForm::getSignGrade() const
{
	return (_signGrade);
}

const unsigned char &AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		std::cout << "Bureaucrat " << bureaucrat.getName() << " tried signing a Aform already signed (" << _name << ")" << std::endl;
	if (bureaucrat.getGrade() > _signGrade)
	{
		std::cout << "Bureaucrat " << bureaucrat.getName() << " couldn't sign Aform " << _name << " because grade is too low!" << std::endl;
		throw AForm::GradeTooLowException();
	}
		_signed = true;
	std::cout << bureaucrat << " signed " << *this << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("[AForm] Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("[AForm] Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, AForm const &obj)
{
	std::cout << "AForm named " << obj.getName() << " (signed: "<< (obj.isSigned() ? "true" : "false") << "). Min sign grade: " <<
		(int) obj.getSignGrade() << " | Min exec grade: " << (int)obj.getExecGrade();
	return (os);
}
