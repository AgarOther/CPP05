/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/06 23:46:38 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat("macron", 8);
		PresidentialPardonForm form("lol");

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("bwaargh", 8);
		RobotomyRequestForm form("lolbutbetter");

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("ecosia", 8);
		ShrubberyCreationForm form("lolultime");

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("ecosia_fake", 8);
		ShrubberyCreationForm form("lolultime");

		bureaucrat.executeForm(form);
		bureaucrat.signForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
