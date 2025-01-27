/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:00 by scraeyme          #+#    #+#             */
/*   Updated: 2025/01/27 14:39:02 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(const char *msg);
		virtual ~GradeTooHighException() throw();
		const char* what() const throw();
	private:
		std::string _message;
};

class GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(const char *msg);
		virtual ~GradeTooLowException() throw();
		const char* what() const throw();
	private:
		std::string _message;
};

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(Bureaucrat const &obj);
		~Bureaucrat();

		Bureaucrat(const std::string &name, int grade);

		std::string getName() const;
		int getGrade() const;

		void incGrade();
		void decGrade();
	private:	
		std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj);
