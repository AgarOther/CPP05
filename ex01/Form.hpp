/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:17:09 by scraeyme          #+#    #+#             */
/*   Updated: 2025/04/30 20:04:02 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, const int &signGrade, const int &execGrade);
		Form(const Form &copy);
		Form &operator=(const Form &obj);
		~Form();

		const std::string &getName() const;
		const bool &isSigned() const;
		const unsigned char &getSignGrade() const;
		const unsigned char &getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

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

#endif