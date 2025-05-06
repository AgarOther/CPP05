/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/07 00:26:17 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	// Subject
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomyf request", "Bender");
	(void) rrf;
	
	Intern intern;
	intern = Intern();
	AForm *shrubbery = intern.makeForm("shrubbery creation", "ecosia");
	if (shrubbery)
	{
		try
		{
			Bureaucrat bureaucrat("Cathy plushie", 1);
			bureaucrat.signForm(*shrubbery);
			bureaucrat.executeForm(*shrubbery);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		delete shrubbery;
	}

	Intern internSecond;
	AForm *presidential = internSecond.makeForm("presidential pardon", "macron");
	if (presidential)
	{
		try
		{
			Bureaucrat bureaucrat("Not Cathy plushie", 150);
			bureaucrat.signForm(*presidential);
			bureaucrat.executeForm(*presidential);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		delete presidential;
	}
	
}
