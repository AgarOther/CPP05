/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/04/30 14:27:56 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat;
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e)
	{
		e.what();
	}
	try
	{
		Bureaucrat bureaucrat("Jesus", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.rankUp();
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Dieu", 0);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Useless", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.rankDown();
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
