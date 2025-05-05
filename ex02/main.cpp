/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/05 14:50:18 by scraeyme         ###   ########.fr       */
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
		Bureaucrat bureaucrat("test", 1);
		PresidentialPardonForm form("lol");

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
