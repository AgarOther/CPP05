/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/02 15:42:55 by scraeyme         ###   ########.fr       */
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
		std::cout << bureaucrat << std::endl;
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Jesus", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.rankUp();
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Dieu", 0);
		std::cout << bureaucrat << std::endl;
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Useless", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.rankDown();
	} catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
