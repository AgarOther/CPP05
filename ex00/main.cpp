/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:51 by scraeyme          #+#    #+#             */
/*   Updated: 2025/04/29 17:00:22 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat ptdrTesQui;
	Bureaucrat bureaucrat("Jesus", 1);
	Bureaucrat pasOuf("Nul", 150);
	Bureaucrat seigneur("Dieu", 5);

	std::cout << ptdrTesQui << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << pasOuf << std::endl;
	std::cout << seigneur << std::endl;
}
