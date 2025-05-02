/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/02 15:43:03 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat;
		Form form;

		bureaucrat.signForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("mbatty", 149);
		Form form("skill boost", 148, 1);

		bureaucrat.signForm(form);
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("scraeyme", 1);
		Form form("skill boost", 1, 1);

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
