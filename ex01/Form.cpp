/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:25:01 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/06 23:49:37 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <iostream>

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "A Form (default) spawned!" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
}

Form &Form::operator=(const Form &obj)
{
	(void) obj;
	return (*this);
}

Form::~Form()
{
	std::cout << "A Form despawned!" << std::endl;
}

Form::Form(const std::string &name, const int &signGrade, const int &execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "A Form (" << name << ") spawned!" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	else if (_signGrade <= 0 || _execGrade <= 0)
		throw Form::GradeTooHighException();
}

const std::string &Form::getName() const
{
	return (_name);
}

const bool &Form::isSigned() const
{
	return (_signed);
}

const unsigned char &Form::getSignGrade() const
{
	return (_signGrade);
}

const unsigned char &Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		std::cout << RED << bureaucrat << " tried signing a form already signed (" << *this << ")" << RESET <<std::endl;
	if (bureaucrat.getGrade() > _signGrade)
	{
		std::cout << RED << bureaucrat << " couldn't sign form " << *this << " because grade is too low!" << RESET <<std::endl;
		throw Form::GradeTooLowException();
	}
		_signed = true;
	std::cout << YELLOW << bureaucrat << " signed " << *this << RESET << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("[Form] Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("[Form] Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, Form const &obj)
{
	std::cout << "Form named " << obj.getName() << " (signed: "<< (obj.isSigned() ? "true" : "false") << " | Min sign grade: " <<
		(int) obj.getSignGrade() << " | Min exec grade: " << (int)obj.getExecGrade() << ")";
	return (os);
}
