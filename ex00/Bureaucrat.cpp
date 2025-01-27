/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:54 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/27 14:42:10 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat unknown spawned!" << std::endl;
	this->_name = "Unknown";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_grade = obj._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
	if (grade < 1)
		throw (GradeTooHighException("Grade is too high!"));
	if (grade > 150)
		throw (GradeTooLowException("Grade is too low!"));
	std::cout << "Bureaucrat " << name << " spawned!" << std::endl;
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destroyed!" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incGrade()
{
	if (_grade - 1 <= 0)
		throw (GradeTooHighException("Grade is too high!"));
	_grade--;
}

void Bureaucrat::decGrade()
{
	if (_grade + 1 <= 0)
		throw (GradeTooLowException("Grade is too low!"));
	_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (os);
}

GradeTooHighException::GradeTooHighException(const char *msg)
{
	_message = msg;
}

GradeTooHighException::~GradeTooHighException() throw()
{
	
}

GradeTooLowException::~GradeTooLowException() throw()
{

}

const char *GradeTooHighException::what() const throw()
{
	return _message.c_str();
}

GradeTooLowException::GradeTooLowException(const char *msg)
{
	_message = msg;
}

const char *GradeTooLowException::what() const throw()
{
	return _message.c_str();
}
