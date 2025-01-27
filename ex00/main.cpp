/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:48 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/27 14:45:56 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	int	grade;

	if (ac != 3)
		return (1);
	grade = atoi(av[2]);
	if (grade == 0)
		return (2);
	try
	{
		Bureaucrat testSubject(av[1], grade);
		std::cout << testSubject;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}