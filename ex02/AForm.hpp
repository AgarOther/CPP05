/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:17:09 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/05 14:40:52 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, const int &signGrade, const int &execGrade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();

		const std::string &getName() const;
		const bool &isSigned() const;
		const unsigned char &getSignGrade() const;
		const unsigned char &getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

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
		bool _signed;
		const unsigned char _signGrade;
		const unsigned char _execGrade;
};

std::ostream &operator<<(std::ostream &os, AForm const &obj);

#endif