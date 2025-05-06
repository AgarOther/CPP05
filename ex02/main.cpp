/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/06 18:45:02 by scraeyme         ###   ########.fr       */
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
		Bureaucrat bureaucrat("test", 8);
		PresidentialPardonForm form("lol");

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("test", 8);
		RobotomyRequestForm form("lol");

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
