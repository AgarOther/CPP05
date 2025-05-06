/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:55 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/06 18:47:14 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	_target = copy._target;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (&obj == this)
		return (*this);
	_target = obj._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= getExecGrade())
	{
		std::cout << "*drilling noises*" << std::endl;
		srand(std::time(NULL));
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully." << std::endl;
		else
			std::cout << _target << "'s robotomization failed." << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}
