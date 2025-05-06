/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:50:27 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/07 00:19:01 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "colors.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "An Intern spawned!" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	*this = copy;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void) obj;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "An Intern despawned!" << std::endl;
}

static AForm *makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	static const std::string names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	static AForm *(*forms[4])(const std::string &target) = {&makeRobotomy, &makeShrubbery, makePresidential};

	for (int i = 0; i < 4; i++)
	{
		if (names[i] == formName)
			return (forms[i](target));
	}
	std::cout << RED << "No form exists for name: " << formName << "." << RESET << std::endl;
	return NULL;
}
