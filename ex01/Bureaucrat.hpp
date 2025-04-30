/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:03:20 by scraeyme          #+#    #+#             */
/*   Updated: 2025/04/30 20:04:17 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const unsigned char &grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		const std::string &getName() const;
		const unsigned char &getGrade() const;
		void rankUp();
		void rankDown();

		void signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		const std::string _name;
		unsigned char _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj);

#endif
