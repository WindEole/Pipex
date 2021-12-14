/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:49:48 by iderighe          #+#    #+#             */
/*   Updated: 2021/12/14 16:41:07 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> // access, unlink, pipe, dup, dup2, execve
# include <sys/types.h> // open, waitpid, wait, fork
# include <sys/stat.h> // open
# include <sys/wait.h> // waitpid, wait
# include <fcntl.h> // open
# include <stdlib.h> // malloc, free
# include <stdio.h> // perror
# include <string.h> // strerror
# include "Libft/libft.h" //fct de la Libft


# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"








#endif
