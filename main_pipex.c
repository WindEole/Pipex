/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:19:10 by iderighe          #+#    #+#             */
/*   Updated: 2021/12/15 15:24:58 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

int	ft_error(char *s, int r)
{
	printf(RED"\n");
	ft_putstr_fd(s, 2);
	printf(RESET"\n");
	return (r);
}

/*char	*ft_trim_path(char *env)
{
	char	*new_env;
	int		i;
	int		j;

	new_env = malloc(sizeof(char) * (ft_strlen(env) - 4));
	if (new_env == NULL)
		return (NULL);
	i = 0;
	j = 5;
	while (env[j])
		new_env[i++] = env[j++];
	new_env[i] = '\0';
	return (new_env);
}*/








/*char	**ft_create_dir_tab(char *path)
{
printf(GREEN"on entre dans create_dir_tab"RESET"\n");
	char	**dir;
	char	*new_path;
	int		i;
	int		j;

	new_path = malloc(sizeof(char) * (ft_strlen(path) - 4));
	if (new_path == NULL)
		return (NULL);
	i = 0;
	j = 5;
	while (path[j])
		new_path[i++] = path[j++];
	new_path[i] = '\0';
printf(GREEN"env = %s"RESET"\n", new_path);
	dir = ft_split_add(new_path, ':');
int	k;
k = 0;
while (dir[k])
{
printf(GREEN"[%d] - [%s]"RESET"\n", k, dir[k]);
k++;
}
	free(new_path);
	return (dir);
}*/






/*int	ft_count_flags(char *av)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (av[++i])
		if (av[i] == ' ')
			j++;
	return (j);
}*/






/*int	ft_check_cmd(char **av, char *path)
{
printf(YELLOW"On entre dans check_cmd\n");
	int		i;
	int		j;
//	char	**dir;
	char	**cmd;

//	dir = ft_create_dir_tab(path);
	i = 0;
	while (++i < 5)
	{
//printf(RED"ici ?"RESET"\n");
		if (i == 2 || i == 3)
//printf(YELLOW"av[%d] = %s"RESET"\n", i, av[i]);
		{
			j = ft_count_flags(av[i]);
			cmd = malloc(sizeof(*cmd) * j);
			if (cmd == NULL)
				return (0);
			j = -1;
			while (av[i][++j])
				if (av[i][j] == ' ')
					cmd = ft_split(av[i], ' ');
		}
	}*/
/*int	k;
k = 0;
while (cmd_f[k])
{
printf(YELLOW" [%d] - [%s]"RESET"\n", k, cmd_f[k]);
k++;
}*/
//	ft_free_split(dir);
//	return (1);
//}





/*char	**ft_create_dir_tab(char *path)
{
printf(GREEN"on entre dans create_dir_tab"RESET"\n");
	char	**dir;
	char	*new_path;
	int		i;
	int		j;

printf(GREEN"env = %s"RESET"\n", new_path);
	dir = ft_split_add(new_path, ':');
int	k;
k = 0;
while (dir[k])
{
printf(GREEN"[%d] - [%s]"RESET"\n", k, dir[k]);
k++;
}
	free(new_path);
	return (dir);
}*/





char	*ft_path_dir(char **env)
{
	char	*path_dir;
	int		i;
	int		j;
	int		k;

	i = 0; 
	while (env[++i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
		&& env[i][3] == 'H' && env[i][4] == '=')
		{
			path_dir = malloc(sizeof(char) * (ft_strlen(env[i]) - 4));
			if (path_dir == NULL)
				return (NULL);
			k = 0;
			j = 5;
			while (env[i][j])
				path_dir[k++] = env[i][j++];
			path_dir[k] = '\0';
			return (path_dir);
		}
	}
	return (NULL);
}





int	ft_check_file(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (i == 1 || i == ac - 1)
			if (access(av[i], F_OK) || access(av[i], R_OK | W_OK) < 0) // || access(av[i], R_OK) < 0 || access(av[i], W_OK) < 0)
				return (0);
	}
	return (1);
}






/*int	main2(int ac, char **av, char **env)
{
int	j = 0;
while (j < 5)
{
printf(PURPLE"av[%d] = %s"RESET"\n", j, av[j]);
j++;
}
	int		i;
//	int		k;
//	t_cmd	**cmd;

	i = -1;
//	k = 0;
	if (ac == 5 && av[0])
	{
printf(PURPLE"OK : ac == 5 !"RESET"\n");
		if (!ft_check_file(av))
			return (ft_error("Error\n- check the files", 1));
		while (env[++i])
		{
//printf(RED"[%d] - "GREEN"[%s]"RESET"\n", k++, env[i++]);
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H')
			ft_check_cmd(av, env[i]);
//			else
//				return (ft_error("Error\n- no valid commands", 1));
		}
	}
	else
		return (ft_error("Error\n- wrong number of arguments", 1));
	return (0);
}*/

int	main(int ac, char **av, char **env)
{
	int	fd[2];
//	int	pid1;
//	int	pid2;
	char	*path_dir;
	char	**std_dir;
	char	**cmd;

	if (pipe(fd) == -1)
		return (1);
	if (ac >= 5 && av[0])
	{
		if (!ft_check_file(ac, av))
			return (ft_error("Error\n- check the files", 1));
		path_dir = ft_path_dir(env);
		if (path_dir == NULL)
			return (ft_error("Error\n- no global variable PATH", 1));
		std_dir = ft_split_add(path_dir, ':');
		if (std_dir == NULL)
			return (ft_error("Error\n- no valid directories", 1));
int	k;
k = 0;
while (std_dir[k])
{
printf(GREEN"[%d] - [%s]"RESET"\n", k, std_dir[k]);
k++;
}
		ft_fork_cmd(av, std_dir);
		free(path_dir);
		ft_free_split(std_dir);

/*
///// Mettre les fork child dans une boucle pour faire le multipipe ! ////
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

//////////////// fin de la boucle de fork !   ///////////////

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);*/
	}
	else
		return (ft_error("Error\n- wrong number of arguments", 1));
	return 0;
}
