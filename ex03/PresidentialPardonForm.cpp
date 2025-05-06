/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:55 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/06 23:48:08 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	_target = copy._target;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (&obj == this)
		return (*this);
	_target = obj._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		std::cout << RED << executor << " tried executing without signing " << *this << RESET << std::endl;
		return;
	}
	if (executor.getGrade() <= getExecGrade())
	{
		std::cout << GREEN << executor << " executed " << *this << RESET << std::endl;
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}
