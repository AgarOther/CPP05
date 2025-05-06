/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:06:25 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/05 14:47:26 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default")
{
	std::cout << "A Bureaucrat (default) spawned!" << std::endl;
	_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (&obj == this)
		return (*this);
	_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat despawned!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned char &grade) : _name(name)
{
	std::cout << "A Bureaucrat (" << name << ") spawned!" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade == 0)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Bureaucrat] Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Bureaucrat] Grade is too low!");
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

const unsigned char &Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::rankUp()
{
	if (_grade - 1 == 0)
		throw Bureaucrat::Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::rankDown()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << (int)obj.getGrade();
	return (os);
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm &form)
{
	form.execute(*this);
}
