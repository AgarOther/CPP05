/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:06:25 by scraeyme          #+#    #+#             */
/*   Updated: 2025/04/29 16:59:28 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default")
{
	std::cout << "A Bureaucrat (default) spawned!" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (&obj == this)
		return (*this);
	this->_grade = obj._grade;
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
		throw GradeTooLowException();
	else if (grade == 0)
		throw GradeTooHighException();
	this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[EXCEPTION] Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[EXCEPTION] Grade is too low!");
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
		throw GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::rankDown()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade += 1;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << (int)obj.getGrade();
	return (os);
}
