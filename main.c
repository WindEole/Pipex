/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:07:13 by iderighe          #+#    #+#             */
/*   Updated: 2021/12/16 17:23:42 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;
	int	pid2;
//// programme correspondant a : ping -c 5 google.com | grep rtt
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
// child process 1 (ex :ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
	{
// child process 2 (ex :grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/*int	main(int argc, char **env)
{
	char	*cmd;
	char	*argv[1];

	cmd = "/usr/bin/touch";
printf("cmd = %s\n", cmd);
	argv[0] = "touch";
printf("argv[0] = %s\n", argv[0]);
	argv[1] = "Hello";
printf("argv[1] = %s\n", argv[1]);
	if(execve(cmd, argv, env) == -1)
		printf("execve failed !\n");
	return (0);
}*/
